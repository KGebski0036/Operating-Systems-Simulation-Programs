#pragma once

#include "TaskAlgorithm.hpp"

class RoundRobin : public TaskAlgorithm
{
  public:
	//Override TaskAlgorithm
	void startAlgorithm(std::vector<Task>& tasks, std::string& fileToSaveOutput) override;
	void printOutput(std::vector<Task>& tasks) override;
	void saveToFile(std::vector<Task>& tasks, std::string& fileToSaveOutput) override;
  private:
	constexpr static size_t quantum_ = 100;
};
