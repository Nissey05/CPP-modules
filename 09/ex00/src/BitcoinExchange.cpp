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
		std::cout << "month" << std::endl;
		if (isGapYear(year))
			return (29);
		else
			return (28);
	}
	return (31);
}

static bool isValidDate(std::string date)
{
	std::string year, month, day;
	size_t delim_1 = date.find('-');
	size_t delim_2 = date.find('-', delim_1 + 1);
	int nb = 0;
	try
	{
		year = date.substr(0, delim_1);
		nb = std::stoi(year);
		if (year.empty())
			return (false);
		month = date.substr(delim_1 + 1, date.size() - delim_2);
		nb = std::stoi(month);
		if (month.empty() || !(nb > 0 && nb < 13))
			return (false);
		day = date.substr(delim_2 + 1);
		nb = std::stoi(day);
		if (day.empty() || !(nb > 0 && nb <= getLastDateMonth(std::stoi(year), std::stoi(month))))
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
		if (delim == str.npos) // throw exception?
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

bool printOccurances(const std::string file, const std::map<std::string, float> data)
{
	std::fstream fs(file, std::ios::in);
	if (!fs)
	{
		std::cerr << "Error: failed to open file!" << std::endl;
		return (false);
	}
	std::string ln;
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