/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:41:19 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/13 17:41:23 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(100), 
		energyPoints(50), attackDamage(20)
{
	name = "shee";
	std::cout << "ClapTrap named " << name << std::endl;
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &clapTrap)
	{
		name = clapTrap.name;
		hitPoints = clapTrap.hitPoints;
		energyPoints = clapTrap.energyPoints;
		attackDamage = clapTrap.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << " causing " << attackDamage << " points of damage!\n";
		--energyPoints;
	}
	else if (hitPoints <= 0)
	{
		std::cout << "A dead ClapTrap named " << name << " tried to attack\n";
	}
	else
	{
		std::cout << "ClapTrap " << name << " tried to attack";
		std::cout << " but it didn't have any energy" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0 && (unsigned int) hitPoints > amount)
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount;
		std::cout << " damage, but is still alive with " << hitPoints
		<< " hp remaining" << std::endl;
	}
	else if (hitPoints > 0 && (unsigned int) hitPoints <= amount)
	{
		std::cout << "ClapTrap " << name << " dies after taking " << amount;
		std::cout << " damage" << std::endl;
		hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << name << " gets hit, but is already dead\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " gets repaired by " << amount;
		hitPoints += amount;
		if (hitPoints > 100)
			hitPoints = 100;
		std::cout << " restoring him to " << hitPoints << " hit points!\n";
		--energyPoints;
	}
	else if (hitPoints <= 0)
	{
		std::cout << "A dead ClapTrap named " << name << " tried to repair\n";
	}
	else
	{
		std::cout << "ClapTrap " << name << " tried to repair";
		std::cout << " but it didn't have any energy" << std::endl;
	}
}

std::string ClapTrap::getName(void)
{
	return ((*this).name);
}