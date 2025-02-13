/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:43:40 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/07 19:43:41 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	// std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(float x, float y) : x(x), y(y)
{
	// std::cout << "floats Point constructor called" << std::endl;

}

// check this copy constructor
Point::Point(const Point &point) : x(point.x), y(point.y)
{
	*this = point;
}

Point::~Point()
{

}

Point &Point::operator = (const Point &point)
{
	if (this != &point)
	{
		// literally nothing to do
	}
	return (*this);
}

float Point::getX() const
{
	return (x.toFloat());
}

float Point::getY() const
{
	return (y.toFloat());
}