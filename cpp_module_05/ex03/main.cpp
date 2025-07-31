/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:56:31 by dbozic            #+#    #+#             */
/*   Updated: 2025/06/25 15:56:33 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern intern;
	AForm *form;
	PresidentialPardonForm *pForm;
	RobotomyRequestForm *rForm;
	ShrubberyCreationForm *sForm;

	form = intern.makeForm("Presidential Pardon Form", "Ed");
	std::cout << *form << std::endl;
	pForm = (PresidentialPardonForm*)form;
	std::cout << pForm->getTarget() << std::endl;
	delete(form);
	form = intern.makeForm("Robotomy Request Form", "Eddie");
	std::cout << *form << std::endl;
	rForm = (RobotomyRequestForm*)form;
	std::cout << rForm->getTarget() << std::endl;
	delete(form);
	form = intern.makeForm("Shrubbery Creation Form", "Eddie's house");
	std::cout << *form << std::endl;
	sForm = (ShrubberyCreationForm*)form;
	std::cout << sForm->getTarget() << std::endl;
	delete(form);
	form = intern.makeForm("Unknown Form", "Ed");
	std::cout << (NULL == form) << std::endl;

	return 0;
}