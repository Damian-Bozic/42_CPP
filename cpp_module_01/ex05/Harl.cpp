/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:44:38 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/24 17:44:39 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "Harl.hpp"

	Harl::Harl()
	{
		// std::cout << "New Harl made" << std::endl;
	}

	Harl::~Harl()
	{
		// std::cout << "Harl destroyed" << std::endl;
	}

	void Harl::debug(void)
	{
		std::cout << "I love having extra bacon for my 7XL-double-cheese-" <<
		"triple-pickle-specialketchup burger. I really do!" << std::endl;
	}

	void Harl::info(void)
	{
		std::cout << "I cannot believe adding extra bacon costs more money." <<
		" You didn’t put enough bacon in my burger! If you did, I wouldn’t" <<
		" be asking for more!" << std::endl;
	}

	void Harl::warning(void)
	{
		std::cout << "I think I deserve to have some extra bacon for free." <<
		" I’ve been coming for years whereas you started working here since"<<
		" last month." << std::endl;
	}

	void Harl::error(void)
	{
		std::cout << "This is unacceptable! I want to speak to the manager" <<
		" now." << std::endl;
	}

	// A pointer array that has a pointer matched to every complain function
	// Then an array of strings with the function call strings
	// Maps are forbidden as per the subject, since they are containers (which
	//  is odd since std::string is technically a container)
	void Harl::complain(std::string level)
	{
		void		(Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, 
						&Harl::warning, &Harl::error};
		std::string	names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

		for (int i = 0; i < 4; i++)
		{
			if (level.compare(names[i]) == 0)
			{
				(this->*ptr_complain[i])();
				return ;
			}
		}
	}