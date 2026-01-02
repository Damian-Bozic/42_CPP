/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:59:33 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/02 16:59:34 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/* default constructor */
template <typename T, int i>
Easyfind<T>::Easyfind() : _size(0), _Easyfind(NULL)
{
}

/* argumented constructor */
template <typename T, int i>
Easyfind<T>::Easyfind(void)
{
	if (size == 0)
		_Easyfind = NULL;
	else
	{
		_Easyfind = new T[size];
		if (!_Easyfind)
			throw (BadNew());
		for (size_t i = 0; i < size; i++)
			_Easyfind[i] = T();
	}
}
/* copy constructor */
template <typename T, int i>
Easyfind<T>::Easyfind(const Easyfind& other)
{
	static_cast<void>(other);
}

/* copy assignment constructor */
template <typename T, int i>
Easyfind<T> &Easyfind<T>::operator=(const Easyfind<T>& other)
{
	delete[](this->_Easyfind);
	_Easyfind = new T[other._size];
	_size = other._size;
	for (size_t i = 0; i < _size; i++)
		this->_Easyfind[i] = other._Easyfind[i];
	return (*this);
}

template <typename T, int i>
T& Easyfind<T>::operator[](size_t index)
{
	if (index >= _size)
		throw (OutOfEasyfindBounds());
	return (*(_Easyfind + index));
}

/* deconstructor */
template <typename T, int i>
Easyfind<T>::~Easyfind()
{
	if (_Easyfind)
		delete[] (_Easyfind);
}

const char *ThrowError::what() const throw()
{
	return("Easyfind threw");
}