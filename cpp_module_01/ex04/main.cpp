/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:28:30 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/21 15:28:31 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed_is_for_losers.hpp"

std::string getFullName(std::string name)
{
	std::string full_name = name.append(".replace");
	return (full_name);
}

std::string fixString(std::string line, std::string str1, std::string str2)
{
	size_t	pos = 0;

	while (1)
	{
		pos = line.find(str1.c_str(), pos, str1.length());
		if (pos == std::string::npos)
			break ;
		line.erase(pos, str1.length());
		line.insert(pos, str2);
		pos += str2.length();
	}
	return (line);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid Input\nUse 'filename', 'old str', 'new str'\n";
		return (0);
	}

	std::fstream infile(argv[1], std::ios::in);
	if (!infile.is_open())
	{
		std::cout << "Invalid Filename" << std::endl;
		return (0);
	}

	std::fstream outfile(getFullName(argv[1]).c_str(), std::ios::out);
	if (!infile.is_open())
	{
		infile.close();
		std::cout << "Invalid Filename" << std::endl;
		return (0);
	}

	std::string line;
	while (getline(infile, line))
	{
		outfile << fixString(line, argv[2], argv[3]) << std::endl;
	}

	infile.close();
	outfile.close();
	return (1);
}


// TEST.TXT

// Hello
// There
// Good
// Sir
// Hello
// There
// Good
// Sir
// HelloThereGoodSir
// HelloThereGoodSirHelloThereGoodSir
