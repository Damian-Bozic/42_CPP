/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:29:06 by dbozic            #+#    #+#             */
/*   Updated: 2025/06/05 16:58:44 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &Cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = Cat;
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &Cat)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &Cat)
	{
		this->type = Cat.type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
