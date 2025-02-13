/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:15:44 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/06 17:15:45 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	// std::cout << "Int constructor called" << std::endl;
	fixed_point_value = input << n_of_fractional_bits;
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float constructor called" << std::endl;
	fixed_point_value = roundf(input * (1 << n_of_fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	// std::cout << "Deconstructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
	{
		fixed_point_value = fixed.getRawBits();
	}
	return (*this);
}

// comparison operators return true or false
bool Fixed::operator > (const Fixed &other)
{
	std::cout << "greater than comparison called" << std::endl;
	if (this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator < (const Fixed &other)
{
	std::cout << "less than comparison called" << std::endl;
	if (this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator >= (const Fixed &other)
{
	std::cout << "greater than or equal comparison called" << std::endl;
	if (this->getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator <= (const Fixed &other)
{
	std::cout << "less than or equal comparison called" << std::endl;
	if (this->getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator == (const Fixed &other)
{
	std::cout << "equal comparison called" << std::endl;
	if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator != (const Fixed &other)
{
	std::cout << "not equal comparison called" << std::endl;
	if (this->getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

// arithmetic operators return new objects
Fixed Fixed::operator + (const Fixed &other)
{
	std::cout << "addition operator called" << std::endl;
	return (Fixed (this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator - (const Fixed &other)
{
	std::cout << "subtraction operator called" << std::endl;
	return (Fixed (this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator * (const Fixed &other)
{
	std::cout << "multiplication operator called" << std::endl;
	return (Fixed (this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator / (const Fixed &other)
{
	std::cout << "division operator called" << std::endl;
	return (Fixed (this->toFloat() / other.toFloat()));
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

// increment / decrement operators
Fixed& Fixed::operator++() // Pre-increment (++x)
{
	fixed_point_value++;
	return(*this);
}

Fixed Fixed::operator++(int) // Post-increment (x++)
{
	Fixed temp = *this;
	fixed_point_value++;
	return (temp);
}

Fixed& Fixed::operator--() // Pre-increment (--x)
{
	fixed_point_value--;
	return(*this);
}

Fixed Fixed::operator--(int) // Post-increment (x--)
{
	Fixed temp = *this;
	fixed_point_value--;
	return (temp);
}

// min / max functions
Fixed& Fixed::min(Fixed &fixed_A, Fixed &fixed_B)
{
	if (fixed_A <= fixed_B)
		return (fixed_A);
	return (fixed_B);
}

const Fixed& Fixed::min(const Fixed &fixed_A, const Fixed &fixed_B)
{
	if (fixed_A.getRawBits() <= fixed_B.getRawBits())
		return (fixed_A);
	return (fixed_B);
}

Fixed& Fixed::max(Fixed &fixed_A, Fixed &fixed_B)
{
	if (fixed_A >= fixed_B)
		return (fixed_A);
	return (fixed_B);
}

const Fixed& Fixed::max(const Fixed &fixed_A, const Fixed &fixed_B)
{
	if (fixed_A.getRawBits() >= fixed_B.getRawBits())
		return (fixed_A);
	return (fixed_B);
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
