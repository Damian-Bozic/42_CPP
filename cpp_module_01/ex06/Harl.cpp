/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:59:34 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/28 16:59:35 by dbozic           ###   ########.fr       */
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
		std::cout << "[ DEBUG ]" << std::endl;
		std::cout << "I love having extra bacon for my 7XL-double-cheese-" <<
		"triple-pickle-specialketchup burger. I really do!" << std::endl;
	}

	void Harl::info(void)
	{
		std::cout << "[ INFO ]" << std::endl;
		std::cout << "I cannot believe adding extra bacon costs more money." <<
		" You didn’t put enough bacon in my burger! If you did, I wouldn’t" <<
		" be asking for more!" << std::endl;
	}

	void Harl::warning(void)
	{
		std::cout << "[ WARNING ]" << std::endl;
		std::cout << "I think I deserve to have some extra bacon for free." <<
		" I’ve been coming for years whereas you started working here since"<<
		" last month." << std::endl;
	}

	void Harl::error(void)
	{
		std::cout << "[ ERROR ]" << std::endl;
		std::cout << "This is unacceptable! I want to speak to the manager" <<
		" now." << std::endl;
	}

	void Harl::complain(int log_level)
	{
		switch (log_level)
		{
			case 1:
				debug();
			case 2:
				info();
			case 3:
				warning();
			default:
				error();
		}
	}