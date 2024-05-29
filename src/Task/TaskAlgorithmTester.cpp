#include "TaskAlgorithmTester.hpp"

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>

#include "Colors.hpp"

TaskAlgorithmTester::TaskAlgorithmTester(size_t numberOfTasks, std::string saveFileName, std::string inputFile) {

	if (inputFile.empty())
		generateRandomTasks(numberOfTasks, saveFileName);
	else
	{
		if(!readTasksFromFile(inputFile))
		{
			std::cout << R << C_EX << "Could not read file. Task are random." << E;
			generateRandomTasks(numberOfTasks, saveFileName);
		}

	}
}

void TaskAlgorithmTester::testAlgorithm(TaskAlgorithm& algorithm, std::string fileToSaveOutput) {
	algorithm.startAlgorithm(tasks_, fileToSaveOutput);
}

void TaskAlgorithmTester::generateRandomTasks(size_t numberOfTasks, std::string saveFileName) {
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
		<< newTask.getExecusionTime()
		<< ", " << newTask.getArrivalTime() << '\n';
	}

	file.close();
}

bool TaskAlgorithmTester::readTasksFromFile(std::string inputFile) {

	std::ifstream file = std::ifstream(inputFile);

	if (!file.is_open())
		return false;

	std::string line;
	while (std::getline(file, line))
	{
		std::string executionTime;
		std::string arricalTime;

		std::stringstream data(line);
		std::getline(data, executionTime, ',');
		std::getline(data, arricalTime, ',');

		Task newtask(std::stoi(executionTime), std::stoi(arricalTime));
		tasks_.push_back(newtask);
	}


	return true;
}
