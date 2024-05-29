#include "PageAlgorithm.hpp"

#include <iostream>
#include <iomanip>

#include "Colors.hpp"

void PageAlgorithm::printStep(size_t needed, size_t missing) {
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

void PageAlgorithm::saveToFile(std::vector<Page>& pages, std::string& fileToSaveOutput) {

}

void PageAlgorithm::printFooter(size_t numberOfSubstitutes) {
	std::cout << E << YELLOW << "Number of substitutes: " << numberOfSubstitutes << E;
}
void PageAlgorithm::printHeder() {
	std::cout << std::left
	<< BLUE << std::setw(5) << "Step" << '|'
	<< ORANGE << std::setw(capacity_ * 3) << "Pages in memory" << '|'
	<< PURPLE << std::setw(8) << "Needed" << '|'
	<< GREEN << std::setw(8) << "Missing" << '|' << '\n';
}
