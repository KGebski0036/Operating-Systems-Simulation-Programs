#pragma once

#include <cstdlib>

class Task
{
  public:
	Task(size_t arrivalTime, size_t timeOfExecusionMiliseconds);
	Task(const Task& task);

	Task& operator=(const Task& task);
	Task& operator-=(size_t execusionTime);
	bool operator==(const Task& task);


	size_t getId() const { return id_; }
	size_t getArrivalTime() const { return arrivalTime_; }
	size_t getExecusionTime() const { return timeOfExecusion_; }
	size_t getWaitingTime() const { return waitingTime_; }
	size_t getTurnAroundTime() const { return turnAroundTime_; }

	void setTimeOfExecusion(size_t timeOfExecusion) { timeOfExecusion_ = timeOfExecusion; }
	void setWaitingTime(size_t waitingTime) { waitingTime_ = waitingTime; }
	void setTurnAroundTime(size_t turnAroundTime) { turnAroundTime_ = turnAroundTime; }

	void execute();

  private:
	size_t id_;
	size_t arrivalTime_;
	size_t timeOfExecusion_;
	size_t waitingTime_;
	size_t turnAroundTime_;
};
