/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:53:25 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/22 17:53:26 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
 AForm("Presidential Pardon Form", 25, 5), target("Unknown Target")
{
	std::cout << "Presidential Form default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
 AForm("Presidential Pardon Form", 25, 5), target(target)
{
	std::cout << "Presidential Form parameterized built constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
 AForm("Presidential Pardon Form", 25, 5)
{
	std::cout << "Presidential Form copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Form deconstructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{
	std::cout << "Presidential Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setSignatureStatus(other.getSignatureStatus());
		this->target = other.getTarget();
	}
	return (*this);
}

std::ostream &operator << (std::ostream &os, const PresidentialPardonForm &presidentialPardonForm)
{
	return (os
	 << "Form \"" << presidentialPardonForm.getName()
	 << "\", sign grade: "
	 << presidentialPardonForm.getSignGrade()
	 << ", exec grade: " << presidentialPardonForm.getExecGrade()
	 << ", target: " << presidentialPardonForm.getTarget()
	 << ", is signed: " << presidentialPardonForm.getSignatureStatus());
}

void PresidentialPardonForm::execute(void) const
{
	std::cout << "Presidential exec called" << std::endl;
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}
