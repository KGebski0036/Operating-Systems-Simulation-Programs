#include "SJF.hpp"

#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>

#include "Colors.hpp"

void SJF::startAlgorithm(std::vector<Task>& tasks, std::string& fileToSaveOutput) {

	std::vector<Task> executedTasks;
	std::vector<Task> executionList;

	std::sort(tasks.begin(), tasks.end(), [](auto& el1, auto& el2){ return el1.getArrivalTime() < el2.getArrivalTime(); });

	size_t time = tasks.front().getArrivalTime();
	auto incommingTask = tasks.begin();

	Task currentExecutedTask = Task(tasks.front());
	size_t timeOfExecution = 0;

	while (true) {

		if (incommingTask != tasks.end() && incommingTask->getArrivalTime() <= time)
		{
			executionList.push_back(*incommingTask);

			if (currentExecutedTask.getExecusionTime() - timeOfExecution > incommingTask->getExecusionTime())
			{
				auto taskOnList = std::find(executionList.begin(), executionList.end(), currentExecutedTask);
				*taskOnList -= timeOfExecution;
				currentExecutedTask.setTimeOfExecusion(timeOfExecution);
				timeOfExecution = 0;
				if (executedTasks.size() > 0)
				{
					currentExecutedTask.setWaitingTime(executedTasks.back().getWaitingTime() + executedTasks.back().getExecusionTime());
					currentExecutedTask.setTurnAroundTime(currentExecutedTask.getWaitingTime() + currentExecutedTask.getExecusionTime());
				}
				else
				{
					currentExecutedTask.setWaitingTime(0);
					currentExecutedTask.setTurnAroundTime(currentExecutedTask.getExecusionTime());
				}
				executedTasks.push_back(currentExecutedTask);
				currentExecutedTask = *incommingTask;
			}

			incommingTask++;
		}

		if (timeOfExecution >= currentExecutedTask.getExecusionTime())
		{
			timeOfExecution = 0;

			if (executedTasks.size() > 0)
			{
				currentExecutedTask.setWaitingTime(executedTasks.back().getWaitingTime() + executedTasks.back().getExecusionTime());
				currentExecutedTask.setTurnAroundTime(currentExecutedTask.getWaitingTime() + currentExecutedTask.getExecusionTime());
			}
			else
			{
				currentExecutedTask.setWaitingTime(0);
				currentExecutedTask.setTurnAroundTime(currentExecutedTask.getExecusionTime());
			}
			executedTasks.push_back(currentExecutedTask);
			executionList.erase(std::remove(executionList.begin(), executionList.end(), currentExecutedTask), executionList.end());

			if (executionList.size() > 0)
				currentExecutedTask = *std::min_element(executionList.begin(), executionList.end(),
					[](auto& a, auto& b){ return a.getExecusionTime() < b.getExecusionTime(); });
			else if (incommingTask != tasks.end())
			{
				currentExecutedTask = *incommingTask;
				time = incommingTask->getArrivalTime();
				incommingTask++;
			}
			else
				break;
		}

		timeOfExecution++;
		time++;
	}

	printOutput(executedTasks);
	saveToFile(executedTasks, fileToSaveOutput);
}

void SJF::printOutput(std::vector<Task>& tasks) {
	std::cout
	<< BLUE << "ID\t"
	<< ORANGE << "ExecusionTime\t"
	<< MAGENTA << "Waiting time\t"
	<< GREEN << "Turn around time\t"
	<< YELLOW << "Arival time"<< E;

	for(const auto& el : tasks) {
		std::cout
		<< BLUE << el.getId() << '\t'
		<< ORANGE << el.getExecusionTime() << "\t\t"
		<< MAGENTA << el.getWaitingTime() << "\t\t"
		<< GREEN << el.getTurnAroundTime() << "\t\t\t"
		<< YELLOW << el.getArrivalTime() << '\n';
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
	<< YELLOW << "\nAverage waiting time = " << BLUE << avWaitingTime
	<< YELLOW << "\nAverage turn around time = " << PINK << avTurnAroundTime << '\n';
}
void SJF::saveToFile(std::vector<Task>& tasks, std::string& fileToSaveOutput) {


	std::ofstream file = std::ofstream(fileToSaveOutput);

	if (!file.is_open())
	{
		std::cout << C_ERROR << "Failed to open a file " << fileToSaveOutput << E;
		exit(1);
	}


	file << "ID\tExecusionTime\tWaiting time\tTurn around time\tArivalTime\n";
	for(const auto& el : tasks) {
		file
		<< el.getId() << '\t'
		<< el.getExecusionTime() <<  "\t\t"
		<< el.getWaitingTime() << "\t\t"
		<< el.getTurnAroundTime() << "\t\t\t"
		<< el.getArrivalTime() << '\n';
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
	<< "\nAverage waiting time = " << avWaitingTime
	<< "\nAverage turn around time = " << avTurnAroundTime << '\n';
}
