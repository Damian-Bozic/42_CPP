/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:10:36 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/30 15:10:37 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP
 #include <iostream>

class Fixed
{
	private:
		int					fixed_point_value;
		static const int	n_of_fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator = (const Fixed &fixed);
		int	getRawBits(void) const; // const at the end means nothing changes
		void setRawBits(int const raw);
};

#endif