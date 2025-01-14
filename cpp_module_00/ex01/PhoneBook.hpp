/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:57:36 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/07 15:57:38 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP
 #include "Contact.hpp"
 #include "HelperFunctions.hpp"
 #include <iostream>
 #include <string>
 #include <cstdlib>

class PhoneBook
{
private:
	Contact contacts[8];
	int		pos;
public:
	PhoneBook();
	~PhoneBook();
	void	add();
	void	search();
	void	print_phonebook();
};

#endif