#pragma once

#include "PageAlgorithm.hpp"

class LRU : public  PageAlgorithm
{
  public:
	//Override PageAlgorithm
	void startAlgorithm(std::vector<Page>& pages, std::string& fileToSaveOutput, size_t capacity) override;
};
