/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:00:54 by dbozic            #+#    #+#             */
/*   Updated: 2025/06/05 17:00:55 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	// for (int i = 0; i > 100; i++)
	// 	ideas[i] = "Thoughtless...";

	int	i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = "Thoughtless...";
		i++;
	}
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	int	i;

	i = 0;
	while (i < 100)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called" << std::endl;
}

Brain &Brain::operator = (const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// for (int i = 0; i > 100; i++)
		// 	this->ideas[i] = other.ideas[i];
		int	i;

		i = 0;
		while (i < 100)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}

std::string Brain::getThought(int pos) const
{
	if (pos <= 99 && pos >= 0)
		return (ideas[pos]);
	return ("No idea..");
}

void Brain::setThought(int pos, std::string Thought)
{
	if (pos <= 99 && pos >= 0)
		ideas[pos] = Thought;
}
