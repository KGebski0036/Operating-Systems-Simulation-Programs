#include <iostream>

#include "Colors.hpp"
#include "TaskAlgorithmTester.hpp"
#include "FCFS.hpp"
#include "LCSF.hpp"

int main() {
	TaskAlgorithmTester tester = TaskAlgorithmTester(10, "task.txt");

	FCFS fcfs = FCFS();
	LCSF lcsf = LCSF();

	std::cout << RED << "---------------------------FCFS---------------------------" << E;
	tester.testAlgorithm(fcfs, "fcfs.out");
	std::cout << RED << "---------------------------LCSF---------------------------" << E;
	tester.testAlgorithm(lcsf, "lcsf.out");
	std::cout << RED << "----------------------------------------------------------" << E;
	return 0;
}
