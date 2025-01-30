/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:23:36 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/17 18:23:37 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const char *name, Weapon &weapon) : m_weapon(weapon)
{
	m_name = name;
}

HumanA::~HumanA()
{
	// std::cout << "Human A " << m_name << " has been destroyed" << std::endl;
	// REMOVE AFTER DEBUG
}

void HumanA::attack()
{
	std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}