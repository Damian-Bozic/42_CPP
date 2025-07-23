/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:39:50 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/17 16:18:09 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include "string.h"
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			signGrade;
		const int			execGrade;
		bool				signature;

	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &AForm);
		virtual ~AForm() = 0;
		AForm &operator = (const AForm &other);
		virtual void		beSigned(Bureaucrat &bureaucrat);
		virtual std::string	getName() const;
		virtual int			getSignGrade() const;
		virtual int			getExecGrade() const;
		virtual bool		getSignatureStatus() const;
		virtual void		setSignatureStatus(bool status);
		virtual	void		tryExecute(Bureaucrat const & executor) const;
		virtual void		execute(void) const;

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

		class FormNotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator << (std::ostream &os, const AForm &aForm);

#endif
