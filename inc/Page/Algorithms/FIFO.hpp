#pragma once

#include "PageAlgorithm.hpp"

class FIFO : public  PageAlgorithm
{
  public:
	//Override PageAlgorithm
	void startAlgorithm(std::vector<Page>& pages, std::string& fileToSaveOutput, size_t capacity) override;
  private:
	size_t nextToReplace = 0;
};
