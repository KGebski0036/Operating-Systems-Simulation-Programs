#include "LRU.hpp"

#include <algorithm>
#include <iostream>
#include <iomanip>

#include "Colors.hpp"

void LRU::startAlgorithm(std::vector<Page>& pages, std::string& fileToSaveOutput, size_t capacity) {
	capacity_ = capacity;
	size_t numberOfSubstitutes = 0;
	std::vector<int> pageUsedInStep;
	pageUsedInStep.resize(capacity_);
	std::fill(pageUsedInStep.begin(), pageUsedInStep.end(), 0);

	printHeder();

	for (size_t i = 0; i <= pages.size(); i++) {

		size_t needed = 0;
		Page page(1);

		if (pages.size() > i)
		{
			page = pages[i];
			needed = page.getId();
		}

		size_t missing = needed;

		for (size_t j = 0; j < memory_.size(); j++) {
			if (memory_[j].getId() == page.getId()) {
				missing = 0;
				pageUsedInStep[j] = i + 1;
			}
		}

		printStep(needed, missing);

		if (missing != 0) {
			if (memory_.size() < capacity_)
			{
				pageUsedInStep[memory_.size()] = i + 1;
				memory_.push_back(page);
			}
			else {
				auto it = std::min_element(pageUsedInStep.begin(), pageUsedInStep.end());
				size_t index = std::distance(pageUsedInStep.begin(), it);
				memory_[index] = page;
				pageUsedInStep[index] = i + 1;
			}

			numberOfSubstitutes++;
		}
	}
	printFooter(numberOfSubstitutes);
}

void LRU::printHeder() {
	std::cout << std::left
	<< BLUE << std::setw(5) << "Step" << '|'
	<< ORANGE << std::setw(capacity_ * 3) << "Pages in memory" << '|'
	<< PURPLE << std::setw(8) << "Needed" << '|'
	<< GREEN << std::setw(8) << "Missing" << '|' << '\n';
}

void LRU::printFooter(size_t numberOfSubstitutes) {
	std::cout << E << YELLOW << "Number of substitutes: " << numberOfSubstitutes << E;
}

void LRU::printStep(size_t needed, size_t missing) {
	static size_t counter = 0;
	counter++;

	std::cout
	<< BLUE << std::setw(5) << counter << '|' << ORANGE;

	for (const auto& page : memory_) {
		std::cout << std::setw(3) << page.getId();
	}

	std::cout
	<< std::right
	<< std::setw(3 * (capacity_ - memory_.size()) + 1) << '|'
	<< std::left;

	std::cout << PURPLE << std::setw(8) << needed << '|';
	if (missing != 0)
		std::cout << GREEN << std::setw(8) << missing << '|' << '\n';
	else
		std::cout << GREEN << std::right << std::setw(9) << '|' << std::left << '\n';
}

void LRU::saveToFile(std::vector<Page>& pages, std::string& fileToSaveOutput) {

}