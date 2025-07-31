/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:47:52 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/23 17:47:54 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() 
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern::~Intern()
{
	std::cout << "Intern deconstructor called" << std::endl;
}

Intern &Intern::operator = (const Intern &other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// literally does nothing...
	}
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm 		*(Intern::*forms[3])(std::string) = {
		&Intern::makePPF,
		&Intern::makeRRF,
		&Intern::makeSCF};
		
	std::string	formsNames[3] = {
		"Presidential Pardon Form",
		"Robotomy Request Form",
		"Shrubbery Creation Form"};
	
	for (int i = 0; i < 3; i++)
	{
		if (formsNames[i] == name)
			return ((this->*forms[i])(target));
	}
	std::cerr << "Error: Bad form name" << std::endl;
	return (NULL);
}

AForm *Intern::makePPF(std::string target)
{
	PresidentialPardonForm *ppf;
	ppf = new PresidentialPardonForm(target);
	return (ppf);
}

AForm *Intern::makeRRF(std::string target)
{
	RobotomyRequestForm *rrf;
	rrf = new RobotomyRequestForm(target);
	return (rrf);
}

AForm *Intern::makeSCF(std::string target)
{
	ShrubberyCreationForm *scf;
	scf = new ShrubberyCreationForm(target);
	return (scf);
}
