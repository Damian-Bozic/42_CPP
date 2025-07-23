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

// AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
//     struct { const char* name; FormCreator creator; } forms[] = {
//         {"shrubbery creation", createShrubbery},
//         {"robotomy request", createRobotomy},
//         {"presidential pardon", createPresidential}
//     };
//     for (size_t i = 0; i < 3; ++i) {
//         if (formName == forms[i].name) {
//             std::cout << "Intern creates " << formName << std::endl;
//             return forms[i].creator(target);
//         }
//     }
//     std::cerr << "Intern: form name not found!" << std::endl;

	// std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	// AForm *(Intern::*forms[3])(std::string) = {&Intern::makePPF, &Intern::makeRRF, &Intern::makeSCF};
	// for (int i = 0; i < 3; i++)
	// {
	// 	if (formNames[i] == form)
	// 		return (this->*forms[i])(target);
	// }

Intern & makeForm(std::string name, std::string target)
{
	void		formClasses[3] = {}
	std::string forms[3] = {
		"Presidential Pardon Form",
		"Robotomy Request Form",
		"Shrubbery Creation Form"}

	// switch ()
	// {	I LOVE IF ELSE TREES OVER THIS
	// 	case name.compare("Presidential Pardon Form") == 0:
	// 		std::cout << "noob dickhead" << std::endl;
	// 		break;
	// 	case name.compare("Robotomy Request Form") == 0:
	// 		std::cout << "bot dickhead" << std::endl;
	// 		break;
	// 	case name.compare("Shrubbery Creation Form") == 0:
	// 		std::cout << "shrubs dickhead" << std::endl;
	// 		break;
	// 	default:
	// 		std::cout << "fucking error" << std::endl;
	// }

	// if (name.compare("Presidential Pardon Form") == 0)
	// {

	// }
	// else if (name.compare("Robotomy Request Form") == 0)
	// {
		
	// }
	// else if (name.compare("Shrubbery Creation Form") == 0)
	// {
		
	// }
	// else
}
