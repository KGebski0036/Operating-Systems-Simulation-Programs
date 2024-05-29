#pragma once

#include <vector>
#include <string>

#include "Page.hpp"
#include "PageAlgorithm.hpp"

class PageAlgorithmTester
{
  public:
	PageAlgorithmTester(size_t numberOfPages, size_t capacity, std::string saveFileName = "", std::string inputFile = "");

	void testAlgorithm(PageAlgorithm& algorithm, std::string fileToSaveOutput);

  private:
	std::vector<Page> pages_;
	size_t memoryCapacity_;
};
