/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:15:36 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/06 17:15:37 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


int main (void)
{
	Fixed a = 20.213f;
	Fixed b = 221.54f;

	std::cout << a << " compared to " << b << std::endl;
	if (a > b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	if (a < b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	if (a >= b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	if (a <= b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	if (a == b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	if (a != b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "adding " << a << " to " << b << std::endl;

	Fixed c = a + b;

	std::cout << "result = " << c << std::endl;

	std::cout << "subracting " << a << " from " << b << std::endl;

	c = a - b;

	std::cout << "result = " << c << std::endl;

	std::cout << "multiplying " << a << " by " << b << std::endl;

	c = a * b;

	std::cout << "result = " << c << std::endl;

	std::cout << "dividing " << a << " by " << b << std::endl;

	c = a / b;

	std::cout << "result = " << c << std::endl;

	std::cout << "iteration tests: " << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	Fixed const d = 10;
	Fixed const e = 0;
	std::cout << "finding max and min of " << d << " and " << e << std::endl;
	std::cout << "max = " << Fixed::max( d, e ) << std::endl;
	std::cout << "min = " << Fixed::min( d, e ) << std::endl;
}

// int main( void )
// {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }
