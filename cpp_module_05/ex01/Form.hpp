/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:39:50 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/05 18:39:51 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "string.h"
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			signGrade;
		const int			execGrade;
		bool				signature;

	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &Form);
		~Form();
		Form &operator = (const Form &bureaucrat);
		void		beSigned(Bureaucrat &bureaucrat);
		void		beExeced(Bureaucrat &bureaucrat);
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getSignatureStatus() const;

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

std::ostream &operator << (std::ostream &os, const Form &form);

#endif
