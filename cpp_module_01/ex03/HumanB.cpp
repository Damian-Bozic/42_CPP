/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:23:40 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/17 18:23:41 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const char *name)
{
	m_name = name;
}

HumanB::~HumanB()
{
	// std::cout << "Human B " << m_name << " has been destroyed" << std::endl;
	// REMOVE AFTER DEBUG
}

void HumanB::attack()
{
	std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	m_weapon = &weapon;
}
