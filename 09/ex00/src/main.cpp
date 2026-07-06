#include <BitcoinExchange.hpp>
#include <vector>
#include <fstream>
#include <iostream>



int main(int argc, char **argv)
{
	std::map<std::string, float> data;
	std::fstream fs("data.csv", std::ios::in);
	if (!fs)
	{
		std::cerr << "Error\nFailed to open file." << std::endl; // throw exception?
		return (1);
	}
	data = import_csv(fs);
	fs.close();
	std::map<std::string, float> req;
	if (argc == 2)
		printOccurances(argv[1], data);
	else
		printOccurances("input.txt", data);
	
}