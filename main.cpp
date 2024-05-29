#include <iostream>

#include "Colors.hpp"
#include "FCFS.hpp"
#include "FIFO.hpp"
#include "LCSF.hpp"
#include "LFU.hpp"
#include "LRU.hpp"
#include "MFU.hpp"
#include "PageAlgorithmTester.hpp"
#include "SJF.hpp"
#include "TaskAlgorithmTester.hpp"
#include "RoundRobin.hpp"

void printMenu();
std::string getDataFromFileInput();

int main() {


	TaskAlgorithmTester tastTester = TaskAlgorithmTester(4, "out/task.txt");
	PageAlgorithmTester pageTester = PageAlgorithmTester(20, 6, "out/pages.txt");

	FCFS fcfs;
	LCSF lcsf;
	SJF sjf;
	RoundRobin roundRobin;

	FIFO fifo;
	LRU lru;
	LFU lfu;
	MFU mfu;

	std::string userInput = "";

	while (userInput != "q")
	{
		printMenu();
		std::cin >> userInput;

		switch (userInput[0])
		{
		  case '0':
			tastTester = TaskAlgorithmTester(4, "out/task.txt", getDataFromFileInput());
			break;
		  case '1':
			pageTester = PageAlgorithmTester(20, 6, "out/pages.txt", getDataFromFileInput());
			break;
		  case '2':
			tastTester.testAlgorithm(fcfs, "out/fcfs.out");
			break;
		  case '3':
			tastTester.testAlgorithm(lcsf, "out/lcsf.out");
			break;
		  case '4':
			tastTester.testAlgorithm(sjf, "out/sjf.out");
			break;
		  case '5':
			tastTester.testAlgorithm(roundRobin, "out/roundRobin.out");
			break;
		  case '6':
			pageTester.testAlgorithm(fifo, "out/fifo.out");
			break;
		  case '7':
			pageTester.testAlgorithm(lru, "out/lru.out");
			break;
		  case '8':
			pageTester.testAlgorithm(lfu, "out/lfu.out");
			break;
		  case '9':
			pageTester.testAlgorithm(mfu, "out/mfu.out");
			break;
		}
	}

	return 0;
}

void printMenu() {
	std::cout << E
	<< GREEN << "q" << RED << " - exit\n"
	<< GREEN << "0" << BLUE << " - choose tasks from file\n"
	<< GREEN << "1" << BLUE << " - choose pages from file\n"
	<< GREEN << "2" << BLUE << " - start task algorithm FCFS\n"
	<< GREEN << "3" << BLUE << " - start task algorithm LCSF\n"
	<< GREEN << "4" << BLUE << " - start task algorithm SJF\n"
	<< GREEN << "5" << BLUE << " - start task algorithm RoundRobin\n"
	<< GREEN << "6" << BLUE << " - start page algorithm FIFO\n"
	<< GREEN << "7" << BLUE << " - start page algorithm LRU\n"
	<< GREEN << "8" << BLUE << " - start page algorithm LFU\n"
	<< GREEN << "9" << BLUE << " - start page algorithm MFU\n";
	std::cout << YELLOW << "Choose a command and type it number: " << GREEN;
}

std::string getDataFromFileInput() {
	std::string input;
	std::cout << YELLOW << "Type path to a file: " << GREEN;
	std::cin >> input;
	return input;
}
