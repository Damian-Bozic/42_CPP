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
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat	Johnbongle("Johnbongle", 40);
		Form		examRegistration("42 Exam Registration Form", 120, 60);
		Form		toiletPass("Exam Toilet Pass", 10, 5);

		std::cout << "COUT TEST >>" << Johnbongle << "<< COUT TEST" << std::endl;
		std::cout << "COUT TEST >>" << examRegistration << "<< COUT TEST" << std::endl;

		Johnbongle.signForm(examRegistration);
		Johnbongle.signForm(examRegistration);
		examRegistration.beExeced(Johnbongle);

		std::cout << "COUT TEST >>" << examRegistration << "<< COUT TEST" << std::endl;
		std::cout << "COUT TEST >>" << toiletPass << "<< COUT TEST" << std::endl;

		Johnbongle.signForm(toiletPass); // this handles the throw internally
		std::cout << "FIRST." << std::endl;
		toiletPass.beSigned(Johnbongle); // this will throw
		std::cout << "SECOND." << std::endl;
		std::cout << "REACHED END." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "FINAL Exception: " << e.what() << std::endl;
	}

	return (0);
}