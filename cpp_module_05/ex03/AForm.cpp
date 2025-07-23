/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:39:46 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/17 16:18:12 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Unknown Form"), signGrade(150), execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name),
 signGrade(signGrade), execGrade(execGrade), signature(0)
{
	std::cout << "Form parameterized built constructor called" << std::endl;
	if (execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (execGrade > 150)
		throw (AForm::GradeTooLowException());
	else if (signGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (signGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &other) : name(other.name), signGrade(other.signGrade),
 execGrade(other.execGrade), signature(other.signature)
{
	std::cout << "Form copy constructor called" << std::endl;
	if (execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (execGrade > 150)
		throw (AForm::GradeTooLowException());
	else if (signGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (signGrade > 150)
		throw (AForm::GradeTooLowException());
	*this = other;
}

AForm::~AForm()
{
	std::cout << "Form deconstructor called" << std::endl;
}

AForm &AForm::operator = (const AForm &other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->signature = other.signature;
	}
	return (*this);
}

std::ostream &operator << (std::ostream &os, const AForm &aForm)
{
	return (os << "Form \"" << aForm.getName() << "\", sign grade: "
	 << aForm.getSignGrade() << ", exec grade: " << aForm.getExecGrade()
	 << ", is signed: " << aForm.getSignatureStatus());
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
	{
		std::cout << bureaucrat.getName() << " couldn't sign "
		 << this->getName() << " because the forms' grade is too high." << std::endl;
		throw (AForm::GradeTooHighException());
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

void AForm::tryExecute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getExecGrade())
	{
		// std::cout << executor << std::endl;
		// std::cout << *this << std::endl;
		if (AForm::getSignatureStatus() == 0)
		{
		std::cout << "Bureaucrat " << executor.getName() << " attempted to execute form: " << this->getName()
		 << ", but failed as the form wasn't signed before hand." << std::endl;
			throw(AForm::FormNotSignedException());
		}
		execute();
		std::cout << "Bureaucrat " << executor.getName() << " successfully executed form: " << this->getName()
		 << "." << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << executor.getName() << " attempted to execute form: " << this->getName()
		 << ", but failed as the form requires a grade of " << this->getExecGrade() << " to execute. "
		 << executor.getName() << " has a grade of " << executor.getGrade() << "." << std::endl;
		throw(AForm::GradeTooHighException());
	}
}

void AForm::execute(void) const
{
	std::cout << "AForm abstract execute, this shouldn't happen" << std::endl;
}

std::string AForm::getName() const
{
	return (name);
}

int	AForm::getSignGrade() const
{
	return (signGrade);
}

int	AForm::getExecGrade() const
{
	return (execGrade);
}

bool AForm::getSignatureStatus() const
{
	return (signature);
}

void AForm::setSignatureStatus(bool status)
{
	signature = status;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return("Form's grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Form's grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return("Form's not signed");
}