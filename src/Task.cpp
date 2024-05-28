#include "Task.hpp"

#include <iostream>

#include "Colors.hpp"

Task::Task(size_t arrivalTime, size_t timeOfExecusionMiliseconds)
	: arrivalTime_(arrivalTime), timeOfExecusion_(timeOfExecusionMiliseconds)
{
	static size_t idCounter = 0;
	id_ = idCounter++;
}

Task::Task(const Task& task) {
	*this = task;
}

Task& Task::operator=(const Task& task) {
	id_ = task.id_;
	arrivalTime_ = task.arrivalTime_;
	timeOfExecusion_ = task.timeOfExecusion_;
	waitingTime_ = task.waitingTime_;
	turnAroundTime_ = task.turnAroundTime_;
	return *this;
}

Task& Task::operator-=(size_t execusionTime) {
	timeOfExecusion_ -= execusionTime;
	return *this;
}

bool Task::operator==(const Task& task) {
	return id_ == task.id_;
}
