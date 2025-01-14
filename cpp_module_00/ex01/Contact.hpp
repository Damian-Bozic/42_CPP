/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:56:50 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/07 15:56:53 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
 #define CONTACT_HPP
 #include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string	nickname;
	std::string number;
	std::string secret;

public: 
	Contact();
	~Contact();

	std::string get_private(std::string variable_name);

	int set_private(std::string variable_name, std::string data);
};

#endif
