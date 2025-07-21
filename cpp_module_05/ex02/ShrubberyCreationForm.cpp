/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:22:57 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/17 16:22:58 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
 AForm("Shrubbery Creation Form", 145, 137), target("Unknown Target")
{
	std::cout << "Shrub Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
 AForm("Shrubbery Creation Form", 145, 137), target(target)
{
	std::cout << "Shrub Form parameterized built constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
 AForm("Shrubbery Creation Form", 145, 137)
{
	std::cout << "Shrub Form copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrub Form deconstructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
{
	std::cout << "Shrub Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setSignatureStatus(other.getSignatureStatus());
		this->target = other.getTarget();
	}
	return (*this);
}

std::ostream &operator << (std::ostream &os, const ShrubberyCreationForm &shrubberyCreationForm)
{
	return (os
	 << "Form \"" << shrubberyCreationForm.getName()
	 << "\", sign grade: "
	 << shrubberyCreationForm.getSignGrade()
	 << ", exec grade: " << shrubberyCreationForm.getExecGrade()
	 << ", target: " << shrubberyCreationForm.getTarget()
	 << ", is signed: " << shrubberyCreationForm.getSignatureStatus());
}

void ShrubberyCreationForm::callExecution(void)
{
	std::cout << "Shrub exec called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}
