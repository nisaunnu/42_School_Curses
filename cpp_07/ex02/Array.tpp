#include "Array.hpp"

template	<typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template	<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n) {}

template	<typename T>
Array<T>::Array(const Array& rhs) : _data(new T[rhs.size()]), _size(rhs.size())
{
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = rhs._data[i];
}

template	<typename T>
Array<T>&	Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		if (_data != NULL)
			delete[] _data;

		_size = rhs._size;
		_data = new T[rhs._size];

		for (unsigned int i = 0; i < _size; i++)
			_data[i] = rhs._data[i];
	}
	return *this;
}

template	<typename T>
Array<T>::~Array() { delete[] _data; }

template	<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

template	<typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

template	<typename T>
unsigned int	Array<T>::size() const { return (_size); }

template	<typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw() { return "Index out of bounds"; }

template	<typename T>
std::ostream&	operator<<(std::ostream& os, const Array<T>& data)
{
	for (unsigned int i = 0; i < data.size(); i++)
		os << data[i];
	return os;
}
