#include "LCSF.hpp"

#include <numeric>
#include <iostream>
#include <fstream>

#include "Colors.hpp"

void LCSF::startAlgorithm(std::vector<Task>& tasks, std::string& fileToSaveOutput) {

	for (int i = tasks.size() - 1; i >= 0; i--) {

		if(i == tasks.size() - 1){
			tasks[i].setWaitingTime(0);
			tasks[i].setTurnAroundTime(tasks[i].getExecusionTime());
			continue;
		}

		Task& taskBefore = tasks[i + 1];
		size_t waitingTime = taskBefore.getWaitingTime() + taskBefore.getExecusionTime();
		tasks[i].setWaitingTime(waitingTime);
		tasks[i].setTurnAroundTime(waitingTime + tasks[i].getExecusionTime());
	}

	printOutput(tasks);
	saveToFile(tasks, fileToSaveOutput);
}

void LCSF::printOutput(std::vector<Task>& tasks) {
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
	<< YELLOW << "\nAverage waiting time = " << BLUE << avWaitingTime
	<< YELLOW << "\nAverage turn around time = " << PINK << avTurnAroundTime << '\n';
}
void LCSF::saveToFile(std::vector<Task>& tasks, std::string& fileToSaveOutput) {


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
	<< "\nAverage waiting time = " << avWaitingTime
	<< "\nAverage turn around time = " << avTurnAroundTime << '\n';
}
