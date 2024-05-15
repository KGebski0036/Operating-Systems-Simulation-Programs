#pragma once

#include <cstdlib>

class Task
{
  public:
	Task(size_t priority, size_t timeOfExecusionMiliseconds);

	size_t getId() const { return id_; }
	size_t getPriority() const { return priority_; }
	size_t getExecusionTimeMiliseconds() const { return timeOfExecusionMiliseconds_; }
	size_t getWaitingTime() const { return waitingTime_; }
	size_t getTurnAroundTime() const { return turnAroundTime_; }

	void setWaitingTime(size_t waitingTime) { waitingTime_ = waitingTime; }
	void setTurnAroundTime(size_t turnAroundTime) { turnAroundTime_ = turnAroundTime; }

	void execute();

  private:
	size_t id_;
	size_t priority_;
	size_t timeOfExecusionMiliseconds_;
	size_t waitingTime_;
	size_t turnAroundTime_;
};
