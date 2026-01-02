/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:00:57 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/30 14:00:58 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <cstdio>
# include <exception>

template <typename T>
class Array
{
	private:
		size_t	_size;
		T*		_array;
	public:
		Array();
		Array(size_t size);
		Array(const Array &other);
		~Array();

		Array		&operator = (const Array &other);
		T&			operator[](size_t index);
		size_t		size(void) const;
};

class OutOfArrayBounds : public std::exception
{
	public:
		const char *what() const throw();
};

# include "Array.tpp"
#endif
