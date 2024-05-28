#include "PageAlgorithmTester.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

#include "Colors.hpp"

PageAlgorithmTester::PageAlgorithmTester(size_t numberOfPages, size_t capasity, std::string saveFileName) {
	std::random_device r;

	pages_.reserve(numberOfPages);
	memoryCapacity_ = capasity;

	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniformDistId(1, numberOfPages / 2);


	std::ofstream file = std::ofstream(saveFileName);

	if (!file.is_open())
	{
		std::cout << C_ERROR << "Failed to open a file " << saveFileName << E;
		exit(1);
	}

	for (size_t i = 0; i < numberOfPages; i++)
	{
		Page newPage = Page((size_t)uniformDistId(e1));
		pages_.push_back(newPage);
		file << "ID " << newPage.getId() << '\n';
	}

	file.close();

}

void PageAlgorithmTester::testAlgorithm(PageAlgorithm& algorithm, std::string fileToSaveOutput) {
	algorithm.startAlgorithm(pages_, fileToSaveOutput, memoryCapacity_);
}
