#include <iostream>

#include "Colors.hpp"
#include "TaskAlgorithmTester.hpp"
#include "FCFS.hpp"
#include "LCSF.hpp"
#include "SJF.hpp"
#include "RoundRobin.hpp"

int main() {
	TaskAlgorithmTester tester = TaskAlgorithmTester(4, "task.txt");

	FCFS fcfs;
	LCSF lcsf;
	SJF sjf;
	RoundRobin roundRobin;

	std::cout << RED << "-------------------------------------FCFS-------------------------------------" << E;
	tester.testAlgorithm(fcfs, "fcfs.out");
	std::cout << RED << "-------------------------------------LCSF-------------------------------------" << E;
	tester.testAlgorithm(lcsf, "lcsf.out");
	std::cout << RED << "-------------------------------------SJF--------------------------------------" << E;
	tester.testAlgorithm(sjf, "sjf.out");
	std::cout << RED << "----------------------------------RoundRobin----------------------------------" << E;
	tester.testAlgorithm(roundRobin, "roundRobin.out");
	std::cout << RED << "------------------------------------------------------------------------------" << E;
	return 0;
}
