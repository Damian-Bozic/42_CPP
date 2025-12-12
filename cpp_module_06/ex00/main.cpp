/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:20:31 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/31 19:20:32 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


//		## ### DEFAULT MAIN ### ##

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string input_argument = argv[1];
		std::cout << input_argument << std::endl;
		ScalarConverter::convert(input_argument);
	}
}
