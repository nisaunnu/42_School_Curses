#include "Span.hpp"
#include <stdexcept>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(number);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + _numbers.size() > _maxSize)
		throw std::runtime_error("Cannot add range: would exceed maximum size");
	_numbers.insert(_numbers.end(), begin, end);
}

void	Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	if (std::distance(begin, end) + _numbers.size() > _maxSize)
		throw std::runtime_error("Cannot add range: would exceed maximum size");
	_numbers.insert(_numbers.end(), begin, end);
}

unsigned int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int>	sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int	minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int>	sorted = _numbers;

	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

const char*	Span::SpanFullException::what() const throw() { return "Span is full";         }
const char*	Span::NoSpanException::what() const throw()   { return "No span can be found"; }
