#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	argv++;
	while (*argv)
	{
		while (**argv)
		{
			if (**argv >= 'a' && **argv <= 'z')
				std::cout << (char)(**argv - 32);
			else 
				std::cout << **argv;
			(*argv)++;
		}
		argv++;
	}
	std::cout << "\n";
	return (0);
}
