#include <iostream>

#include "Colors.hpp"
#include "TaskAlgorithmTester.hpp"
#include "PageAlgorithmTester.hpp"
#include "FCFS.hpp"
#include "LCSF.hpp"
#include "SJF.hpp"
#include "FIFO.hpp"
#include "RoundRobin.hpp"

int main() {
	TaskAlgorithmTester tastTester = TaskAlgorithmTester(4, "out/task.txt");
	PageAlgorithmTester pageTester = PageAlgorithmTester(20, 6, "out/pages.txt");

	FCFS fcfs;
	LCSF lcsf;
	SJF sjf;
	RoundRobin roundRobin;

	FIFO fifo;

	std::cout << RED << "-------------------------------------FCFS-------------------------------------" << E;
	tastTester.testAlgorithm(fcfs, "out/fcfs.out");
	std::cout << RED << "-------------------------------------LCSF-------------------------------------" << E;
	tastTester.testAlgorithm(lcsf, "out/lcsf.out");
	std::cout << RED << "-------------------------------------SJF--------------------------------------" << E;
	tastTester.testAlgorithm(sjf, "out/sjf.out");
	std::cout << RED << "----------------------------------RoundRobin----------------------------------" << E;
	tastTester.testAlgorithm(roundRobin, "out/roundRobin.out");
	std::cout << RED << "------------------------------------------------------------------------------" << E;

	std::cout << RED << "-------------------------------------FIFO-------------------------------------" << E;
	pageTester.testAlgorithm(fifo, "out/fifo.out");
	std::cout << RED << "------------------------------------------------------------------------------" << E;
	return 0;
}

