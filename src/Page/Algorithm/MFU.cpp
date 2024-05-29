#include "MFU.hpp"

#include <algorithm>
#include <iostream>
#include <iomanip>

#include "Colors.hpp"

void MFU::startAlgorithm(std::vector<Page>& pages, std::string& fileToSaveOutput, size_t capacity) {
	capacity_ = capacity;
	size_t numberOfSubstitutes = 0;
	std::vector<int> pagesUsedCounter;
	pagesUsedCounter.resize(capacity_);
	std::fill(pagesUsedCounter.begin(), pagesUsedCounter.end(), 0);

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
				pagesUsedCounter[j]++;
			}
		}

		printStep(needed, missing);

		if (missing != 0) {
			if (memory_.size() < capacity_)
			{
				pagesUsedCounter[memory_.size()] = 1;
				memory_.push_back(page);
			}
			else {
				auto it = std::max_element(pagesUsedCounter.begin(), pagesUsedCounter.end());
				size_t index = std::distance(pagesUsedCounter.begin(), it);
				memory_[index] = page;
				pagesUsedCounter[index] = 1;
			}

			numberOfSubstitutes++;
		}
	}
	printFooter(numberOfSubstitutes);
}

