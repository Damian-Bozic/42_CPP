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

int main(void)
{
	// srand(time(0));
	std::cout << "\nCanonical Orthodox Form Tests\n" << std::endl;
	{
		ShrubberyCreationForm shrubs1("42_London_Campus"); // They need it
		std::cout << " " << shrubs1 << std::endl;

		ShrubberyCreationForm shrubs2(shrubs1);
		shrubs2.setSignatureStatus(1);
		std::cout << " " << shrubs2 << std::endl;

		ShrubberyCreationForm shrubs3("42_Lisbon_Campus");
		std::cout << " " << shrubs3 << std::endl;

		shrubs3 = shrubs2;
		std::cout << " " << shrubs3 << std::endl;
	}

	std::cout << "\nFully authorised bureaucrat test\n" << std::endl;
	try
	{
		Bureaucrat George("George", 137);
		ShrubberyCreationForm shrubs("42_Warsaw_Campus");
		George.signForm(shrubs);
		George.executeForm(shrubs);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}
	std::cout << "\nBureaucrat without sufficient grade to exec test\n" << std::endl;
	try
	{
		Bureaucrat George("George", 138);
		ShrubberyCreationForm shrubs("42_Warsaw_Campus");
		George.signForm(shrubs);
		George.executeForm(shrubs);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}
	std::cout << "\nBureaucrat forgot to sign form test\n" << std::endl;
	try
	{
		Bureaucrat George("George", 137);
		ShrubberyCreationForm shrubs("42_Warsaw_Campus");
		George.executeForm(shrubs);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}
	std::cout << "\nBureaucrat without sufficient grade to sign test\n" << std::endl;
	try
	{
		Bureaucrat George("George", 146);
		ShrubberyCreationForm shrubs("42_Warsaw_Campus");
		George.signForm(shrubs);
		George.executeForm(shrubs);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}

	std::cout << "\nRobotomy Tests \n" << std::endl;
	try
	{
		Bureaucrat George("George", 8);
		RobotomyRequestForm Robotomy("Bob (Your Uncle)");

		George.signForm(Robotomy);
		George.executeForm(Robotomy);
		George.executeForm(Robotomy);
		George.executeForm(Robotomy);
		George.executeForm(Robotomy);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}

	std::cout << "\nRobotomy Tests Again \n" << std::endl;
	try
	{
		Bureaucrat George("George", 8);
		RobotomyRequestForm Robotomy("John");

		George.signForm(Robotomy);
		George.executeForm(Robotomy);
		George.executeForm(Robotomy);
		George.executeForm(Robotomy);
		George.executeForm(Robotomy);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}

	std::cout << "\nPresidential Tests \n" << std::endl;
	try
	{
		Bureaucrat George("George", 2);
		PresidentialPardonForm Pardon("Some dude");

		George.signForm(Pardon);
		George.executeForm(Pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}
return (0);
}
