#include "Task.hpp"

#include <chrono>
#include <iostream>
#include <thread>

#include "Colors.hpp"

Task::Task(size_t priority, size_t timeOfExecusionMiliseconds)
	: priority_(priority), timeOfExecusionMiliseconds_(timeOfExecusionMiliseconds)
{
	static size_t idCounter = 0;
	id_ = idCounter++;
}

void Task::execute() {
	std::cout << BLUE << "Task with id " << GREEN << id_ << MAGENTA << " start" << E;

	std::chrono::milliseconds timespan(timeOfExecusionMiliseconds_);
	std::this_thread::sleep_for(timespan);

	std::cout << BLUE << "Task with id " << GREEN << id_ << YELLOW << " finish" << E;
}
