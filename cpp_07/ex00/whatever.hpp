#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template	<typename T>
void	swap(T&first, T& second)
{
	T	temp;

	temp = first;
	first = second;
	second = temp;
}

template	<typename T>
const T&	min(const T& first, const T& second)
{
	return ((first < second) ? first : second);
}

template	<typename T>
const T&	max(const T& first, const T& second)
{
	return ((first > second) ? first : second);
}

#endif
