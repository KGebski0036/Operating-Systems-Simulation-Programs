#pragma once

#include <string>
#include <vector>

#include "Page.hpp"

class PageAlgorithm
{
  public:
	virtual void startAlgorithm(std::vector<Page>& pages, std::string& fileToSaveOutput, size_t capacity) = 0;
	virtual void saveToFile(std::vector<Page>& pages, std::string& fileToSaveOutput) = 0;
	virtual void printStep(size_t needed, size_t missing) = 0;
  protected:
  	std::vector<Page> memory_;
	size_t capacity_ = 0;
};

