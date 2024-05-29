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
