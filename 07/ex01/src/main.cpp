#include "iter.hpp"

#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec = {1, 2, 3};
	::iter(&vec[0], vec.size(), inc<int>); // + 1
	::iter(&vec[0], vec.size(), print<int>);
	std::cout << std::endl;
	::iter(&vec[0], vec.size(), dec<int>); // 0
	::iter(&vec[0], vec.size(), dec<int>); // -1
	::iter(&vec[0], vec.size(), print<int>);
	std::cout << std::endl;
	::iter(&vec[0], vec.size(), inc<int>); // 0
	::iter(&vec[0], vec.size(), inc<int>); // + 1
	::iter(&vec[0], vec.size(), inc<int>); // + 2
	::iter(&vec[0], vec.size(), inc<int>); // + 3
	::iter(&vec[0], vec.size(), inc<int>); // + 4
	::iter(&vec[0], vec.size(), inc<int>); // + 5
	::iter(&vec[0], vec.size(), print<int>);
}