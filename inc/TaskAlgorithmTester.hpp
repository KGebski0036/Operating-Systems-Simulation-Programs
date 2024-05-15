#pragma once

#include <vector>
#include <string>

#include "Task.hpp"
#include "TaskAlgorithm.hpp"

class TaskAlgorithmTester
{
  public:
	TaskAlgorithmTester(size_t numberOfTasks, std::string saveFileName = "");

	void testAlgorithm(TaskAlgorithm& algorithm, std::string fileToSaveOutput);

  private:
	std::vector<Task> tasks_;
};

