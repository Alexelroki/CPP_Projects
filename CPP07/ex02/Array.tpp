#include <cstddef>

template <typename T>
Array<T>::Array( void ) : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array( unsigned int n ) : _elements(NULL), _size(n)
{
	if (n > 0)
		_elements = new T[n]();
}

template <typename T>
Array<T>::Array( const Array<T>& other ) : _elements(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_elements = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
		{
			_elements[i] = other._elements[i];
		}
	}
}

template <typename T>
Array<T>&			Array<T>::operator=( const Array<T>& other )
{
	if (this != &other)
	{
		T*	new_elements = NULL;
		if (other._size > 0)
		{
			new_elements = new T[other._size]();
			for (unsigned int i = 0; i < other._size; i++)
			{
				new_elements[i] = other._elements[i];
			}
		}
		if (_elements)
			delete[] _elements;
		_elements = new_elements;
		_size = other._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void )
{
	if (_elements)
		delete[] _elements;
}

template <typename T>
T&				Array<T>::operator[]( unsigned int index )
{
	if (index >= _size || !_elements)
		throw OutOfBoundsException();
	return (_elements[index]);
}

template <typename T>
const T&		Array<T>::operator[]( unsigned int index ) const
{
	if (index >= _size || !_elements)
		throw OutOfBoundsException();
	return (_elements[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <typename T>
const char* 	Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds.");
}
