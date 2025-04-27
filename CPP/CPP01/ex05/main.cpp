#include "Harl.hpp"

int main()
{
	Harl	harl;

	std::cout << "Printing all harl could say." << std::endl << std::endl;
	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("something else");
	std::cout << "Now you have 5 chances to make harl say something." << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "input: ";
		std::string input;
		getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cerr << "^D" << std::endl;
			return (1);
		}
		harl.complain(input);
		std::cout << std::endl;
	}
	return (0);
}