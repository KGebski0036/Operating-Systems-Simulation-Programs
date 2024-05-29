#pragma once

#include "PageAlgorithm.hpp"

class LRU : public  PageAlgorithm
{
  public:
	//Override PageAlgorithm
	void startAlgorithm(std::vector<Page>& pages, std::string& fileToSaveOutput, size_t capacity) override;
	void saveToFile(std::vector<Page>& pages, std::string& fileToSaveOutput) override;
	void printStep(size_t needed, size_t missing) override;
  private:
	void printHeder();
	void printFooter(size_t numberOfSubstitutes);
};
