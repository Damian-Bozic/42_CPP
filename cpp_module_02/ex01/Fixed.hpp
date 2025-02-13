/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:50:56 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/03 19:50:56 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP
 #include <iostream>
 #include <math.h>
 
class Fixed
{
	private:
		int					fixed_point_value;
		static const int	n_of_fractional_bits = 8; // changes the precision

	public:
		Fixed();
		Fixed(const int input); // new function
		Fixed(const float input); // new function
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator = (const Fixed &fixed);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const; // new function
		int toInt(void) const; // new function
};

std::ostream& operator << (std::ostream& ostrm, const Fixed &fixed); // new

// int has 16 bytes, of which 8 represent the fraction

#endif