/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:29:06 by dbozic            #+#    #+#             */
/*   Updated: 2025/06/05 16:59:08 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &WrongCat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = WrongCat;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &WrongCat)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &WrongCat)
	{
		this->type = WrongCat.type;
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow" << std::endl;
}
