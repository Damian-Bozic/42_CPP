/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:19:53 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/07 17:19:54 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* default constructor */
Span::Span() : _max_size(0)
{
}

/* argumented constructor */
Span::Span(unsigned int max_size) : _max_size(max_size)
{
}
/* copy constructor */
Span::Span(const Span& other)
{
	*this = other;
}

/* copy assignment constructor */
Span &Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	_max_size = other._max_size;
	this->_container.clear();
	for (size_t i = 0; i < _max_size; i++)
		this->_container.push_back(other._container.at(i));
	return (*this);
}

/* deconstructor */
Span::~Span()
{
}

void Span::addNumber(unsigned int number_to_add)
{
	if (_container.size() == _max_size)
		throw(OutOfRoom());
	_container.push_back(number_to_add);
}
unsigned int Span::shortestSpan(void)
{
	// Vector::iterator min_max_iterator;
	// min_max_iterator = std::minmax_element(_container.begin(),
	// 	container.end())
	// unsigned int smallest_in_set = _container.
	// unsigned int largest_in_set;
	return (1);
}
unsigned int Span::longestSpan(void)
{
	return (1);
}

const char *Span::OutOfRoom::what() const throw()
{
	return("There is no more room to add elements");
}