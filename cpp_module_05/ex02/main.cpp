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

int main(void)
{
	std::cout << "\nCanonical Orthodox Form Tests\n" << std::endl;
	{
		ShrubberyCreationForm shrubs1("42 London Campus"); // They need it
		std::cout << " " << shrubs1 << std::endl;

		ShrubberyCreationForm shrubs2(shrubs1);
		shrubs2.setSignatureStatus(1);
		std::cout << " " << shrubs2 << std::endl;

		ShrubberyCreationForm shrubs3("42 Lisbon Campus");
		std::cout << " " << shrubs3 << std::endl;

		shrubs3 = shrubs2;
		std::cout << " " << shrubs3 << std::endl;
	}

	std::cout << "\nFully authorised bureaucrat test\n" << std::endl;
	try
	{
		Bureaucrat George("George", 137);
		ShrubberyCreationForm shrubs("42 Warsaw Campus");
		shrubs.beSigned(George);
		shrubs.executeForm(George);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}
	std::cout << "\nBureaucrat without sufficient grade to exec test\n" << std::endl;
	try
	{
		Bureaucrat George("George", 138);
		ShrubberyCreationForm shrubs("42 Warsaw Campus");
		shrubs.beSigned(George);
		shrubs.executeForm(George);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}
	std::cout << "\nBureaucrat forgot to sign form test\n" << std::endl;
	try
	{
		Bureaucrat George("George", 137);
		ShrubberyCreationForm shrubs("42 Warsaw Campus");
		// shrubs.beSigned(George);
		shrubs.executeForm(George);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}
	std::cout << "\nBureaucrat without sufficient grade to sign test\n" << std::endl;
		try
	{
		Bureaucrat George("George", 146);
		ShrubberyCreationForm shrubs("42 Warsaw Campus");
		shrubs.beSigned(George);
		shrubs.executeForm(George);
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}
	return (0);
}
