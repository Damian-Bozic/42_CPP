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

/*Behaviour for wrong iterators is undefined. Backwards iterators aren't detectable using std::distance until C++11*/
void Span::addIteratorRange(std::vector<unsigned int>::iterator start,
	std::vector<unsigned int>::iterator end)
{
	unsigned int size_to_add = std::distance(start, end);
	if (_container.size() + size_to_add > _max_size)
		throw(OutOfRoom());
	for (unsigned int i = 0; i < size_to_add; i++)
		_container.push_back(start[i]);	
}

unsigned int Span::shortestSpan(void) const
{
	if (_container.size() < 2)
		throw(NotEnoughElements());
	std::vector<unsigned int> sorted_container = _container;
	unsigned int shortest_span = sorted_container.at(0) + sorted_container.at(1);
	std::sort(sorted_container.begin(), sorted_container.end());
	for (unsigned int i = 1; i < sorted_container.size(); i++)
	{
		if (_container.at(i) - _container.at(i - 1) < shortest_span)
			shortest_span = _container.at(i) - _container.at(i - 1);
	}
	return (shortest_span);
}
unsigned int Span::longestSpan(void) const
{
	if (_container.size() < 2)
		throw(NotEnoughElements());
	std::vector<unsigned int>::const_iterator iterator_to_max = std::max_element(_container.begin(), _container.end());
	std::vector<unsigned int>::const_iterator iterator_to_min = std::min_element(_container.begin(), _container.end());
	return (*iterator_to_max - *iterator_to_min);
}

unsigned int Span::getNumber(unsigned int pos) const
{
	return _container.at(pos);
}

unsigned int Span::getSize(void) const
{
	return (_container.size());
}


const char *Span::OutOfRoom::what() const throw()
{
	return("There is no more room to add elements");
}

const char *Span::NotEnoughElements::what() const throw()
{
	return("There are not enough elements in the vector to find a span");
}

#include <sstream>

std::ostream &operator<<(std::ostream &os, const Span &span)
{
	unsigned int span_len = span.getSize();
	os << "Span Class Debug\nspan_len = " << span_len << "\n";
	for (unsigned int i = 0; i < span_len; i++)
	{
		os << "span[" << i << "] = " << span.getNumber(i);
		if (i != span_len - 1)
			os << "\n";
	}
	return (os);
}