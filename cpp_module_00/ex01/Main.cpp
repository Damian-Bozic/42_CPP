/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:57 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/13 13:47:59 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "HelperFunctions.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input_line;

	std::cout << "PhoneBook start" << std::endl;
	while(1)
	{
		input_line = get_input("Enter Command: ");
		if (input_line.compare("ADD") == 0)
			phonebook.add();
		else if (input_line.compare("SEARCH") == 0)
			phonebook.search();
		else if (input_line.compare("EXIT") == 0)
		{
			phonebook.~PhoneBook(); // I don't have to do this
			exit(1);
		}
		else
			std::cout << "Invalid command, try ADD, SEARCH, or EXIT" << std::endl;
	}
	return (1);
}