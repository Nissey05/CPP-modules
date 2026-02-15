#include <random>

int RNG(int a, int b)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> uid(a, b);
	return(uid(gen));
}