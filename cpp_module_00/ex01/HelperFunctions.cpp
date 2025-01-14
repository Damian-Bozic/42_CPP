/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper_functions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:50:29 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/13 13:50:31 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HelperFunctions.hpp"

std::string get_input(std::string prompt)
{
	std::string input;

	while (1)
	{
		std::cout << prompt;
		if (!(std::getline (std::cin, input)))
			exit(0);
		if (input[0])
			break;
	}
	return (input);
}

int ft_stoi(std::string input)
{
	long	temp = 0;
	int		i = 0;
	int		sign = 1;

	if (input.size() > 11)
		return (0);
	while (i < (int)input.size())
	{
		if (input[0] == '-' && i == 0)
		{
			sign = -1;
			i++;
		}
		if (!isdigit(input[i]))
			return (0);
		temp = temp * 10;
		temp = temp + (input[i] - 48);
		i++;
	}
	if (temp > 2147483648 || (temp == 2147483648 && sign == 1))
		return (0);
	temp = temp * sign;
	return ((int)temp);
}
