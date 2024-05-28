#include "RoundRobin.hpp"

#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "Colors.hpp"

void RoundRobin::startAlgorithm(std::vector<Task>& tasks, std::string& fileToSaveOutput) {

	std::vector<Task> executedTasks;
	std::vector<Task> tasksCopy = tasks;

	auto currentTask = tasksCopy.begin();

	while (tasksCopy.size() > 0)
	{
		Task copyTask = *currentTask;

		if (currentTask->getExecusionTime() > quantum_)
		{
			copyTask.setTimeOfExecusion(quantum_);
			*currentTask -= quantum_;
		}
		else
		{
			copyTask.setTimeOfExecusion(currentTask->getExecusionTime());
			tasksCopy.erase(std::remove(tasksCopy.begin(), tasksCopy.end(), *currentTask), tasksCopy.end());
			currentTask--;
		}

		if (executedTasks.size() > 0)
		{
			copyTask.setWaitingTime(executedTasks.back().getWaitingTime() + executedTasks.back().getExecusionTime());
			copyTask.setTurnAroundTime(copyTask.getWaitingTime() + copyTask.getExecusionTime());
		}
		else
		{
			copyTask.setWaitingTime(0);
			copyTask.setTurnAroundTime(copyTask.getExecusionTime());
		}
		executedTasks.push_back(copyTask);

		currentTask++;
		if (currentTask >= tasksCopy.end())
			currentTask = tasksCopy.begin();
	}

	printOutput(executedTasks);
	saveToFile(executedTasks, fileToSaveOutput);
}

void RoundRobin::printOutput(std::vector<Task>& tasks) {
	std::cout
	<< BLUE << "ID\t"
	<< ORANGE << "ExecusionTime\t"
	<< MAGENTA << "Waiting time\t"
	<< GREEN << "Turn around time" << E;

	for(const auto& el : tasks) {
		std::cout
		<< BLUE << el.getId() << '\t'
		<< ORANGE << el.getExecusionTime() << "\t\t"
		<< MAGENTA << el.getWaitingTime() << "\t\t"
		<< GREEN << el.getTurnAroundTime() << '\n';
	}

	size_t avWaitingTime = std::accumulate(tasks.begin(), tasks.end(), 0,
		[](size_t result, const auto& el){
			return result + el.getWaitingTime();
		});

	size_t avTurnAroundTime = std::accumulate(tasks.begin(), tasks.end(), 0,
		[](size_t result, const auto& el){
			return result + el.getTurnAroundTime();
		});

	std::cout
	<< YELLOW << "\nAverage waiting time = " << BLUE << avWaitingTime / tasks.size()
	<< YELLOW << "\nAverage turn around time = " << PINK << avTurnAroundTime / tasks.size() << '\n';
}
void RoundRobin::saveToFile(std::vector<Task>& tasks, std::string& fileToSaveOutput) {


	std::ofstream file = std::ofstream(fileToSaveOutput);

	if (!file.is_open())
	{
		std::cout << C_ERROR << "Failed to open a file " << fileToSaveOutput << E;
		exit(1);
	}


	file << "ID\tExecusionTime\tWaiting time\tTurn around time\n";
	for(const auto& el : tasks) {
		file
		<< el.getId() << '\t'
		<< el.getExecusionTime() <<  "\t\t"
		<< el.getWaitingTime() << "\t\t"
		<< el.getTurnAroundTime() << '\n';
	}

	size_t avWaitingTime = std::accumulate(tasks.begin(), tasks.end(), 0,
		[](size_t result, const auto& el){
			return result + el.getWaitingTime();
		});

	size_t avTurnAroundTime = std::accumulate(tasks.begin(), tasks.end(), 0,
		[](size_t result, const auto& el){
			return result + el.getTurnAroundTime();
		});

	file
	<< "\nAverage waiting time = " << avWaitingTime / tasks.size()
	<< "\nAverage turn around time = " << avTurnAroundTime / tasks.size() << '\n';
}
