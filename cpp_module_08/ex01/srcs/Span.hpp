/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:19:48 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/07 17:19:49 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
	private:
		unsigned int				_max_size;
		std::vector<unsigned int>	_container;
	public:
		Span();
		Span(unsigned int _max_size);
		Span(const Span &other);
		~Span();

		Span &operator = (const Span &other);
		void addNumber(unsigned int number_to_add);
		void addIteratorRange(std::vector<unsigned int>::iterator start,
			std::vector<unsigned int>::iterator end);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
		unsigned int getNumber(unsigned int pos) const;
		unsigned int getSize(void) const;

	class OutOfRoom : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class NotEnoughElements : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const Span &span);

#endif
