/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:58:24 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/02 16:58:25 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <cstdio>
# include <exception>

template <typename T, int i>
class Easyfind
{
	private:
		size_t	_size;
		T*		_Easyfind;
	public:
		Easyfind();
		Easyfind(void);
		Easyfind(const Easyfind &other);
		~Easyfind();
};

class BadNew : public std::exception
{
	public:
		const char *what() const throw();
};

class OutOfEasyfindBounds : public std::exception
{
	public:
		const char *what() const throw();
};

# include "easyfind.tpp"
#endif
