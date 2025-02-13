/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:51:01 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/03 19:51:02 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	// fixed_point_value = input * pow(2, n_of_fractional_bits);
	fixed_point_value = input << n_of_fractional_bits;
}
// 0000 0000   0000 1010 = 10	as RAW
// 0000 1010   0000 0000 = 2560 as RAW
//    ^^^         ^^^
//  integers   fractional


Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point_value = roundf(input * (1 << n_of_fractional_bits));
}
// 5.75 = 101.11
// 0000 0101 . 1100 0000 = 1472 as RAW
//    ^^^         ^^^
//  integers   fractional
//
// 0000 0000   0000 0101.11	visualisation of a float
// 0000 0101   1100 0000	bits get shifted left by 8
//
// 5.75 * 256 = 1472
//
// roundf is used incase we end up having something like
//  1472.3 or 1472.7, it rounds any fractional number into
//  an integer, increasing accuracy

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	// fixed_point_value = fixed.fixed_point_value;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
	{
		fixed_point_value = fixed.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	fixed_point_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float) fixed_point_value / pow(2, n_of_fractional_bits));
}

int Fixed::toInt(void) const
{
	return (fixed_point_value >> n_of_fractional_bits);
}

std::ostream& operator << (std::ostream& ostrm, const Fixed &fixed)
{
	ostrm << fixed.toFloat();
	return (ostrm);
}
