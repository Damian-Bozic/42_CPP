/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:39:46 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/05 18:39:46 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Unknown Form"), signGrade(150), execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : name(name),
 signGrade(signGrade), execGrade(execGrade), signature(0)
{
	std::cout << "Form parameterized built constructor called" << std::endl;
	if (execGrade < 1)
		throw (Form::GradeTooHighException());
	else if (execGrade > 150)
		throw (Form::GradeTooLowException());
	else if (signGrade < 1)
		throw (Form::GradeTooHighException());
	else if (signGrade > 150)
		throw (Form::GradeTooLowException());
}


Form::Form(const Form &other) : name(other.name), signGrade(other.signGrade),
 execGrade(other.execGrade), signature(other.signature)
{
	std::cout << "Form copy constructor called" << std::endl;
	if (execGrade < 1)
		throw (Form::GradeTooHighException());
	else if (execGrade > 150)
		throw (Form::GradeTooLowException());
	else if (signGrade < 1)
		throw (Form::GradeTooHighException());
	else if (signGrade > 150)
		throw (Form::GradeTooLowException());
	*this = other;
}

Form::~Form()
{
	std::cout << "Form deconstructor called" << std::endl;
}

Form &Form::operator = (const Form &other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->signature = other.signature;
	}
	return (*this);
}

std::ostream &operator << (std::ostream &os, const Form &form)
{
	return (os << "Form \"" << form.getName() << "\", sign grade: "
	 << form.getSignGrade() << ", exec grade: " << form.getExecGrade()
	 << ", is signed: " << form.getSignatureStatus());
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
	{
		std::cout << bureaucrat.getName() << " couldn't sign "
		 << this->getName() << " because the forms' grade is too high." << std::endl;
		throw (Form::GradeTooHighException());
	}
	if (this->getSignatureStatus() == 0)
	{
		this->signature = 1;
		std::cout << bureaucrat.getName() << " signed " << this->getName()
		 << "." << std::endl;
	}
	else
	{
		std::cout << bureaucrat.getName() << " was about to sign "
		 << this->getName() << " but found that it was already signed."
		 << std::endl;
	}
}

void	Form::beExeced(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getExecGrade())
	{
		std::cout << bureaucrat.getName() << " couldn't execute "
		 << this->getName() << " because the forms' grade was too high." << std::endl;
		throw (Form::GradeTooHighException());
	}
	if (this->getSignatureStatus() == 0)
	{
		std::cout << bureaucrat.getName() << " was about to exec the form "
		 << this->getName() << " but realised it hadn't been signed yet." << std::endl;
	}
	else
	{
		std::cout << bureaucrat.getName() << " Executed form " << this->getName()
		 << "." << std::endl;
	}
}

std::string Form::getName() const
{
	return (name);
}

int	Form::getSignGrade() const
{
	return (signGrade);
}

int	Form::getExecGrade() const
{
	return (execGrade);
}

bool Form::getSignatureStatus() const
{
	return (signature);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return("Form's grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Form's grade too low");
}
