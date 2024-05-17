#pragma once

#include "TaskAlgorithm.hpp"

class SJF : public TaskAlgorithm
{
  public:
	//Override TaskAlgorithm
	void startAlgorithm(std::vector<Task>& tasks, std::string& fileToSaveOutput) override;
	void printOutput(std::vector<Task>& tasks) override;
	void saveToFile(std::vector<Task>& tasks, std::string& fileToSaveOutput) override;
};
