/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:10:25 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/06 15:10:26 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	pos = 0;
}

PhoneBook::~PhoneBook()
{
	for (int i = 0; i < 8; i++)
		contacts[i].~Contact();
}

static std::string shorten_string_for_phonebook(std::string input)
{
	std::string rtn;
	int			i = 0;

	rtn = "          ";
	while (input[i])
	{
		if (input[i] < 32 || input[i] > 126)
			input[i] = ' ';
		i++;
	}
	i = input.size();
	if (i > 10)
	{
		rtn = input;
		rtn.erase(9, i - 9);
		rtn.push_back('.');
	}
	else
	{
		rtn.replace(10 - i, i, input);
	}
	rtn.push_back('|');

	return (rtn);
}

void PhoneBook::print_phonebook()
{
	std::string temp;
	int	i = 0;

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	while (i < 8)
	{
		std::cout << "|         " << i + 1 << "|";
		temp = shorten_string_for_phonebook(contacts[i].get_private("first_name"));
		std::cout << temp;
		temp = shorten_string_for_phonebook(contacts[i].get_private("last_name"));
		std::cout << temp;
		temp = shorten_string_for_phonebook(contacts[i].get_private("nickname"));
		std::cout << temp << std::endl;
		i++;
	}
}

void PhoneBook::search()
{
	int			search_pos;
	std::string	temp;

	print_phonebook();
	temp = get_input("Enter index of the contact you would like to view: ");
	search_pos = ft_stoi(temp);
	if (search_pos < 1 || search_pos > 8)
	{
		std::cout << "Invalid SEARCH option" << std::endl;
		return ;
	}
	std::cout << "First name: " << contacts[search_pos -1].get_private("first_name") << std::endl;
	std::cout << "Last name: " << contacts[search_pos - 1].get_private("last_name") << std::endl;
	std::cout << "Nickname: " << contacts[search_pos - 1].get_private("nickname") << std::endl;
	std::cout << "Number: " << contacts[search_pos - 1].get_private("number") << std::endl;
	std::cout << "Deepest darkest secret: " << contacts[search_pos - 1].get_private("secret") << std::endl;
}

static int	is_valid_number(std::string input)
{
	int i = 0;

	while (input[i])
	{
		if (!isdigit(input[i]))
			return (0);
		i++;
	}
	if (i == 9)
		return (1);
	return (0);
}

void PhoneBook::add()
{
	std::string input;

	input = get_input("Input contact's first name: ");
	contacts[pos % 8].set_private("first_name", input);
	input = get_input("Input contact's last name: ");
	contacts[pos % 8].set_private("last_name", input);
	input = get_input("Input contact's nickname: ");
	contacts[pos % 8].set_private("nickname", input);
	while (1)
	{
		std::cout << "Input contact's number: ";
		if (!(std::getline (std::cin, input)))
			exit(0);
		if (is_valid_number(input))
			break;
		std::cout << "Please use format XXXxxxXXX\n";
	}
	contacts[pos % 8].set_private("number", input);
	input = get_input("Input contacts deepest darkest secret: ");
	contacts[pos % 8].set_private("secret", input);
	pos++;
}

// VVV  CODE GRAVEYARD  VVV

//Wide chars wont work since when one is found -1 or 0 is returned, instead of the
//width of the multibyte character

/* std::string shorten_string_for_phonebook(std::string input)
{
	std::string rtn;
	wchar_t		wide_str[1028];
	int			total_width;
	int			len;
	int			i = 0;

	std::cout << "\n\n";

	rtn = "          ";
	len = mbstowcs(wide_str, input.c_str(), 1028);
	total_width = 0;
	std::cout << "input has length of " << len << std::endl;
	while (i < len)
	{
		std::cout << "\nLength left: " << len << std::endl;
		total_width = total_width + wcwidth(wide_str[i]);
		i++;;
	}
	std::cout << "\nWidth found for " << input << ", total_width: " << total_width << std::endl;
	if (total_width > 10)
	{
		rtn = input;
		rtn.erase(9, total_width - 9);
		rtn.push_back('.');
		//cut down to 9 and put a . at the end
	}
	else
	{
		rtn.replace(10 - total_width, total_width, input);
		//add spaces to the beginning so that its 10 chars long
	}
	rtn.push_back('|');

	std::cout << "\n\n";

	return (rtn);
} */