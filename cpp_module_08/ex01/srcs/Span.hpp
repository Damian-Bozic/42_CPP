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
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

	class OutOfRoom : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif
