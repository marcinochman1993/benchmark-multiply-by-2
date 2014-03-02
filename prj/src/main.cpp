#include "Benchmark.hpp"
#include "MultiplyBy2.hpp"
#include <string>
#include <fstream>
#include <thread>

int main(int argc, char* argv[])
{
	Benchmark<MultiplyBy2> bench;
	if(argc == 1)
	{
		bench.start(std::cin, std::cin);
		bench.saveAsCSV(std::cout);
		return 0;
	}

	if(argc != 4)
	{
		std::cerr << "Zla ilosc argumentow\n";
		return -1;
	}

	std::string arg1(argv[1]);
	std::string arg2(argv[2]);
	std::string arg3(argv[3]);
	std::ifstream input(arg1);
	std::ifstream correctOutputFile(arg2);
	std::ofstream output(arg3);
	if(!input.is_open())
	{
		std::cerr << "Nie mozna otworzyc pliku " << arg1 << std::endl;
		return -2;
	}

	if(!correctOutputFile.is_open())
	{
		std::cerr << "Nie mozna otworzyc pliku " << arg2 << std::endl;
		return -2;
	}

	if(!output.is_open())
	{
		std::cerr << "Nie mozna otworzyc pliku " << arg3 << std::endl;
		return -2;
	}

	bench.start(input, correctOutputFile);
	bench.saveAsCSV(output);

	return 0;
}
