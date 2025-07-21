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
	std::cout << "Cat default constructor called" << std::endl;
	type = "cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	brain = new Brain(*other.get_brain());
	// this->brain = other.brain;
	// this->brain->setThought(0, "cheese");
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor called" << std::endl;
	delete brain;
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete(brain);
		brain = new Brain(*other.get_brain());
	}
	return (*this);
}

Brain	*Cat::get_brain() const
{
	return (brain);
}


void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
