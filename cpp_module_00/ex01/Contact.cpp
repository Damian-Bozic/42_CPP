/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:59:26 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/07 17:59:27 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() // constructor
{
	first_name = "";
	last_name = "";
	nickname = "";
	number = "XXXXXXXXX";
	secret = "";
}

Contact::~Contact() // deconstructor
{
}

std::string Contact::get_private(std::string variable_name)
{
	if (variable_name == "first_name")
		return (first_name);
	if (variable_name == "last_name")
		return (last_name);
	if (variable_name == "nickname")
		return (nickname);
	if (variable_name == "number")
		return (number);
	if (variable_name == "secret")
		return (secret);
	return (0);
}

int Contact::set_private(std::string variable_name, std::string data)
{
	if (variable_name == "first_name")
		first_name = data;
	if (variable_name == "last_name")
		last_name = data;
	if (variable_name == "nickname")
		nickname = data;
	if (variable_name == "number")
		number = data;
	if (variable_name == "secret")
		secret = data;
	return (0);
}
