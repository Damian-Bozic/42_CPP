/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:15:44 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/30 14:15:50 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* default constructor */
template <typename T>
Array<T>::Array() : _size(0), _array(NULL)
{
}

/* argumented constructor */
template <typename T>
Array<T>::Array(size_t size) : _size(size)
{
	if (size == 0)
		_array = NULL;
	else
	{
		_array = new T[size];
		if (!_array)
			throw (BadNew());
		for (size_t i = 0; i < size; i++)
			_array[i] = T();
	}
}
/* copy constructor */
template <typename T>
Array<T>::Array(const Array& other)
{
	static_cast<void>(other);
}

/* copy assignment constructor */
template <typename T>
Array<T> &Array<T>::operator=(const Array<T>& other)
{
	static_cast<void>(other);
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw (OutOfArrayBounds());
	return (*(_array + index));
}

/* deconstructor */
template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete[] (_array);
}

template <typename T>
size_t Array<T>::size(void) const
{
	return (_size);
}

const char *BadNew::what() const throw()
{
	return("Array failed to allocate on the heap using new");
}

const char *OutOfArrayBounds::what() const throw()
{
	return("Array attempted to access an index outside its size");
}
