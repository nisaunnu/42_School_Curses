#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << std::endl << "[ USAGE ERROR ]" << std::endl << std::endl
				  << "Usage:" << std::endl
				  << "    ./scalar_converter <input>" << std::endl << std::endl
				  << "Examples of valid <input> values:" << std::endl
				  << "    - Single character    : 'a'  → interpreted as char (enclosed in single quotes, 1 character)" << std::endl
				  << "    - Integers            : 42, -5, +100" << std::endl
				  << "        * float values    : 3.14f, -0.5f, +2.0f" << std::endl
				  << "        * double values   : 3.14, -0.5, +2.0" << std::endl
				  << "    - Special values" << std::endl
				  << "        * float           : nanf, +inff, -inff" << std::endl
				  << "        * double          : nan, +inf, -inf" << std::endl << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}
