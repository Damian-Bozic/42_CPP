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

int main(void)
{
	try
	{
		Bureaucrat gregethan;

		std::cout << "COUT TEST >>" << gregethan << "<< COUT TEST" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bobbery("bobbery", 1);	

		std::cout << bobbery.getName() << " " << bobbery.getGrade() << std::endl;
		try
		{
			bobbery.increment();
		}
		catch(std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << bobbery.getName() << " " << bobbery.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bobbery("bobbery", 150);	

		std::cout << bobbery.getName() << " " << bobbery.getGrade() << std::endl;
		try
		{
			bobbery.decrement();
		}
		catch(std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << bobbery.getName() << " " << bobbery.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bobbery("bobbery", 149);	

		std::cout << bobbery.getName() << " " << bobbery.getGrade() << std::endl;
		try
		{
			bobbery.decrement();
		}
		catch(std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << bobbery.getName() << " " << bobbery.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bobbery("bobbery", 149);	

		std::cout << bobbery.getName() << " " << bobbery.getGrade() << std::endl;
		try
		{
			bobbery.increment();
		}
		catch(std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << bobbery.getName() << " " << bobbery.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}