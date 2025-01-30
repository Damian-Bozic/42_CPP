/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:59:39 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/28 16:59:40 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int find_level(std::string level)
{
	if (level.compare("DEBUG") == 0)
		return (1);
	if (level.compare("INFO") == 0)
		return (2);
	if (level.compare("WARNING") == 0)
		return (3);
	if (level.compare("ERROR") == 0)
		return (4);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid amount of inputs" << std::endl;
		return (0);
	}

	int log_level = find_level(argv[1]);
	if (!log_level)
	{
		std::cout << "Invalid level name" << std::endl;
		return (0);
	}
	
	Harl harl;
	harl.complain(log_level);
	return (1);
}