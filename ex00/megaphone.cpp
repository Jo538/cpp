#include <iostream>

int touppercase(std::string str)
{
	int i = 0;

	while (i < str.length())
	{
		std::cout << (char)std::toupper(str.at(i));
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	argv++;
	while (*argv)
	{
		touppercase(*argv);
		argv++;
	}
	std::cout << "\n";
	return (0);
}
