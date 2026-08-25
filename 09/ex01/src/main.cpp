#include <stack>
#include <string>
#include <sstream>
#include <iostream>

static bool is_operator(const std::string &str)
{
	if (str == "+" || str == "-" || str == "*" || str == "/")
		return (true);
	return (false);
}

static bool is_number(const std::string &str)
{
	int nb = std::stoi(str);
	if (nb >= 0 && nb <= 9)
		return (true);
	return (false);
}

static int do_operator(const std::string &str, const int &a, const int &b)
{
	if (str == "+")
		return (a + b);
	else if (str == "-")
		return (a - b);
	else if (str == "*")
		return (a * b);
	else
		return (a / b);
}

int main(int argc, char **argv)
{
	auto err_and_exit = []() {
		std::cerr << "Error" << std::endl;
		exit(1);
	};
	if (argc != 2)
		err_and_exit();
	std::stack<int> s;
	std::stringstream ss;
	ss << argv[1];
	std::string str;
	try
	{
		while (ss >> str)
		{
			if (is_operator(str))
			{
				if (s.empty())
					err_and_exit();
				int a = s.top();
				s.pop();
				if (!s.empty())
					s.top() = do_operator(str, s.top(), a);
				else
					err_and_exit();
			}
			else if (is_number(str))
				s.push(std::stoi(str));
			else
				err_and_exit();
		}
	}
	catch (const std::exception &e)
	{
		err_and_exit();
	}
	if (s.size() == 1)
		std::cout << s.top() << std::endl;
	else
		err_and_exit();
}