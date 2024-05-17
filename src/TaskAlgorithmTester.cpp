#include "TaskAlgorithmTester.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

#include "Colors.hpp"

TaskAlgorithmTester::TaskAlgorithmTester(size_t numberOfTasks, std::string saveFileName) {
	std::random_device r;
	tasks_.reserve(numberOfTasks);

	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniformDistTime(10, 500);
	std::uniform_int_distribution<int> uniformDistPriority(1, 100);


	std::ofstream file = std::ofstream(saveFileName);

	if (!file.is_open())
	{
		std::cout << C_ERROR << "Failed to open a file " << saveFileName << E;
		exit(1);
	}

	for (size_t i = 0; i < numberOfTasks; i++)
	{
		Task newTask = Task((size_t)uniformDistPriority(e1), (size_t)uniformDistTime(e1));
		tasks_.push_back(newTask);
		file
		<< "ID " << newTask.getId()
		<< ", execution time: " << newTask.getExecusionTime()
		<< ", arrival time: " << newTask.getArrivalTime() << '\n';
	}

}

void TaskAlgorithmTester::testAlgorithm(TaskAlgorithm& algorithm, std::string fileToSaveOutput) {
	algorithm.startAlgorithm(tasks_, fileToSaveOutput);
}
