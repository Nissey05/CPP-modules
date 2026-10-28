#include <BitcoinExchange.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

static bool isGapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0)
			return (true);
		else if (year % 400 == 0)
			return (true);
	}
	return (false);
}

static int getLastDateMonth(const int year, const int month)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (30);
	if (month == 2)
	{
		if (isGapYear(year))
			return (29);
		else
			return (28);
	}
	return (31);
}

static bool checkNoNum(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if ((char)str[i] < '0' || (char)str[i] > '9')
			return (false);
	}
	return (true);
}

static bool isValidDate(std::string date)
{
	std::string year, month, day;
	size_t delim_1 = date.find('-');
	size_t delim_2 = date.find('-', delim_1 + 1);
	if (delim_1 == std::string::npos || delim_2 == std::string::npos)
		return (false);
	int nb = 0;
	
	try
	{
		year = date.substr(0, delim_1);
		if (year.empty() ||!checkNoNum(year))
			return (false);
		nb = std::stoi(year);
		month = date.substr(delim_1 + 1, delim_2 - delim_1 - 1);
		if (month.empty() || !checkNoNum(month))
			return (false);
		nb = std::stoi(month);
		if (!(nb > 0 && nb < 13))
			return (false);
		day = date.substr(delim_2 + 1);
		if (day.empty() || !checkNoNum(day))
			return (false);
		nb = std::stoi(day);
		if (!(nb > 0 && nb <= getLastDateMonth(std::stoi(year), std::stoi(month))))
			return (false);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
	return (true);
}

std::map <std::string, float>import_csv(std::fstream &fs)
{
	std::string str;
	std::getline(fs, str);
	std::map <std::string, float>data;
	while (std::getline(fs, str))
	{
		size_t delim = str.find(',');
		if (delim == str.npos)
			return (data);
		data[str.substr(0, delim)] = std::stof(str.substr(delim + 1));
	}
	return (data);
}

float getRate(const std::string &date, const std::map<std::string, float> data)
{
	std::map<std::string, float>::const_iterator it = data.upper_bound(date);
	if (it == data.begin())
		return (0.0f);
	--it;
	return (it->second);
}

static bool checkNoFloat(std::string str)
{
	size_t end = str.find('.');
	if (end == std::string::npos)
		return (checkNoNum(str));
	for (size_t i = 0; i < end; i++)
	{
		if ((char)str[i] < '0' || (char)str[i] > '9')
			return (false);
	}
		for (size_t i = end + 1; i < str.size(); i++)
	{
		if ((char)str[i] < '0' || (char)str[i] > '9')
			return (false);
	}
	return (true);
}

bool printOccurances(const std::string file, const std::map<std::string, float> data)
{
	std::fstream fs(file, std::ios::in);
	if (!fs)
	{
		std::cerr << "Error: failed to open file!" << std::endl;
		return (false);
	}
	std::string ln;
	std::getline(fs, ln);
	if (ln != "date | value")
	{
		std::cerr << "Error: bad input => " << ln << std::endl;
		fs.close();
		return (false);
	}
	while (std::getline(fs, ln))
	{
		size_t delim = ln.find(" | ");
		std::string date, value;
		if (delim == std::string::npos)
			std::cerr << "Error: bad input => " << ln << std::endl;
		else if ((date = ln.substr(0, delim)).empty() || !isValidDate(date))
			std::cerr << "Error: bad input => " << ln << std::endl;
		else if ((value = ln.substr(delim + 3)).empty())
			std::cerr << "Error: bad input => " << ln << std::endl;
		else
		{
			try
			{
				if (!checkNoFloat(value))
				{
					std::cerr << "Error: bad input => " << ln << std::endl;
					continue;
				}
				float fl = std::stof(value);
				if (fl < 0)
					std::cerr << "Error: not a positive number." << std::endl;
				else if (fl > 1000)
					std::cerr << "Error: too large a number." << std::endl;
				else
					std::cout << date << " => " << fl << " = " << fl * getRate(date, data) << std::endl;
			}
			catch (std::exception &e)
			{
				std::cerr << "Error: not a number." << std::endl;
			}
		}
	}
	fs.close();
	return (true);
}