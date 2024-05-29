#pragma once

#include <string>
#include <vector>

#include "Task.hpp"

class TaskAlgorithm
{
  public:
	virtual void startAlgorithm(std::vector<Task>& tasks, std::string& fileToSaveOutput) = 0;
	virtual void printOutput(std::vector<Task>& tasks) = 0;
	virtual void saveToFile(std::vector<Task>& tasks, std::string& fileToSaveOutput) = 0;
	virtual ~TaskAlgorithm() {}
};

