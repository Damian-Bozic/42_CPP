/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:09:49 by dbozic            #+#    #+#             */
/*   Updated: 2025/06/25 15:56:29 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "string.h"
# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
		
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &Bureaucrat);
		~Bureaucrat();
		void increment();
		void decrement();
		Bureaucrat &operator = (const Bureaucrat &bureaucrat);
		// std::ostream &operator << (std::ostream &os, const Bureaucrat &bureaucrat);
		std::string getName() const;
		int getGrade() const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator << (std::ostream &os, const Bureaucrat &bureaucrat);

#endif
