#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other)               { (void)other;               }
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty()) return false;

	size_t	i = 0;

	if (literal[0] == '-' || literal[0] == '+') i++;

	for (; i < literal.length(); i++)
		if (!isdigit(literal[i])) return false;

	return true;
}

bool	ScalarConverter::isFloat(const std::string& literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
	if (literal.empty() || literal[literal.length() - 1] != 'f') return false;

	size_t	i = 0;
	bool	hasDot = false;

	if (literal[0] == '-' || literal[0] == '+') i++;

	for (; i < literal.length() - 1; i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot) return false;
			hasDot = true;
		}
		else if (!isdigit(literal[i])) return false;
	}

	return hasDot;
}

bool	ScalarConverter::isDouble(const std::string& literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;
	if (literal.empty()) return false;

	bool	hasDot = false;
	size_t	i = 0;

	if (literal[0] == '-' || literal[0] == '+') i++;

	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot) return false;
			hasDot = true;
		}
		else if (!isdigit(literal[i])) return false;
	}

	return hasDot;
}

bool	ScalarConverter::isPseudoLiteral(const std::string& literal)
{
	return (literal == "-inf" || literal == "+inf" || literal == "nan" ||
			literal == "-inff" || literal == "+inff" || literal == "nanf");
}

void	ScalarConverter::convertChar(const std::string& literal)
{
	char	c = literal[1];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::convertInt(const std::string& literal)
{
	long long	value = std::atoll(literal.c_str());

	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;

		return;
	}

	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	ScalarConverter::convertFloat(const std::string& literal)
{
	float	value = std::atof(literal.c_str());

	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << std::fixed << std::setprecision(3);
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void	ScalarConverter::convertDouble(const std::string& literal)
{
	double	value = std::atof(literal.c_str());

	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << std::fixed << std::setprecision(3);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}

void	ScalarConverter::convertPseudoLiteral(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& literal)
{
	if (isPseudoLiteral(literal))
		convertPseudoLiteral(literal);
	else if (isChar(literal))
		convertChar(literal);
	else if (isInt(literal))
		convertInt(literal);
	else if (isFloat(literal))
		convertFloat(literal);
	else if (isDouble(literal))
		convertDouble(literal);
	else
		std::cout << "Invalid input" << std::endl;
}
