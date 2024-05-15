#pragma once

#include <cstdlib>

class Task
{
  public:
	Task(size_t priority, size_t timeOfExecusionMiliseconds);

	size_t getId() const { return id_; }
	size_t getPriority() const { return priority_; }

	void execute();

  private:
	size_t id_;
	size_t priority_;
	size_t timeOfExecusionMiliseconds_;
};
