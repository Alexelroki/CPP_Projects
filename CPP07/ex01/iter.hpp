#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef> // size_t

template <typename T, typename F>
void		iter(T* array, const size_t length, F func)
{
	if (!array || !func)
		return;
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif
