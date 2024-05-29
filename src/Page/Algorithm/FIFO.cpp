#include "FIFO.hpp"

#include <algorithm>
#include <iostream>
#include <iomanip>

#include "Colors.hpp"

void FIFO::startAlgorithm(std::vector<Page>& pages, std::string& fileToSaveOutput, size_t capacity) {
	capacity_ = capacity;
	size_t numberOfSubstitutes = 0;
	printHeder();

	for (size_t i = 0; i <= pages.size(); i++) {

		size_t needed = 0;
		size_t missing = 0;
		Page page(1);

		if (pages.size() > i)
		{
			page = pages[i];
			needed = page.getId();
		}

		if(std::none_of(memory_.begin(), memory_.end(), [needed](Page& el) {return el.getId() == needed;})) {
			missing = needed;
		}

		printStep(needed, missing);

		if (missing != 0) {
			if (memory_.size() < capacity_)
				memory_.push_back(page);
			else
				memory_[nextToReplace % capacity_] = page;

			numberOfSubstitutes++;
			nextToReplace++;
		}
	}
	printFooter(numberOfSubstitutes);
}

void FIFO::printHeder() {
	std::cout << std::left
	<< BLUE << std::setw(5) << "Step" << '|'
	<< ORANGE << std::setw(capacity_ * 3) << "Pages in memory" << '|'
	<< PURPLE << std::setw(8) << "Needed" << '|'
	<< GREEN << std::setw(8) << "Missing" << '|' << '\n';
}

void FIFO::printFooter(size_t numberOfSubstitutes) {
	std::cout << E << YELLOW << "Number of substitutes: " << numberOfSubstitutes << E;
}

void FIFO::printStep(size_t needed, size_t missing) {
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

void FIFO::saveToFile(std::vector<Page>& pages, std::string& fileToSaveOutput) {

}
