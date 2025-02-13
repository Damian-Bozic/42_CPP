/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:15:40 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/06 17:15:40 by dbozic           ###   ########.fr       */
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
		static const int	n_of_fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator = (const Fixed &fixed);
		bool operator > (const Fixed &other);
		bool operator < (const Fixed &other);
		bool operator >= (const Fixed &other);
		bool operator <= (const Fixed &other);
		bool operator == (const Fixed &other);
		bool operator != (const Fixed &other);
		Fixed operator + (const Fixed &other);
		Fixed operator - (const Fixed &other);
		Fixed operator * (const Fixed &other);
		Fixed operator / (const Fixed &other);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		static Fixed& min(Fixed &fixed_A, Fixed &fixed_B);
		static const Fixed& min(const Fixed &fixed_A, const Fixed &fixed_B);
		static Fixed& max(Fixed &fixed_A, Fixed &fixed_B);
		static const Fixed& max(const Fixed &fixed_A, const Fixed &fixed_B);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator << (std::ostream& ostrm, const Fixed &fixed);


#endif