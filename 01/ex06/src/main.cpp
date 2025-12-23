#include "Harl.hpp"

int main(void)
{
	Harl h;
	
	h.complain("DEBUG");
	h.complain("WARNING");
	h.complain("dd");
	h.complain("ERROR");
	h.complain("INFO");
	h.complain("");
}