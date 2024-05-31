#include "PageAlgorithmTester.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

#include "Colors.hpp"

PageAlgorithmTester::PageAlgorithmTester(size_t numberOfPages, size_t capasity, std::string saveFileName, std::string inputFile) {

	memoryCapacity_ = capasity;

	if (inputFile.empty())
		generateRandomPages(numberOfPages, saveFileName, capasity);
	else
	{
		if(!readPagesFromFile(inputFile))
		{
			std::cout << R << C_EX << "Could not read file. Pages are random." << E;
			generateRandomPages(numberOfPages, saveFileName, capasity);
		}

	}
}

void PageAlgorithmTester::testAlgorithm(PageAlgorithm& algorithm, std::string fileToSaveOutput) {
	algorithm.startAlgorithm(pages_, fileToSaveOutput, memoryCapacity_);
}

void PageAlgorithmTester::generateRandomPages(size_t numberOfPages, std::string saveFileName, size_t capasity) {
	std::random_device r;

	pages_.clear();
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
		file <<  newPage.getId() << '\n';
	}

	file.close();
}
bool PageAlgorithmTester::readPagesFromFile(std::string inputFile) {

	std::ifstream file = std::ifstream(inputFile);

	if (!file.is_open())
		return false;

	std::string line;
	pages_.clear();
	while (std::getline(file, line))
	{
		Page newpage(std::stoi(line));
		pages_.push_back(newpage);
	}


	return true;
}
