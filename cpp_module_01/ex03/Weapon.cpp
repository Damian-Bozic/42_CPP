/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:23:13 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/17 18:23:14 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream> // REMOVE AFTER DEBUG

Weapon::Weapon(std::string weapon)
{
	m_type = weapon;
}

Weapon::~Weapon()
{
	// std::cout << "Weapon " << m_type << " has been destroyed" << std::endl;
	// REMOVE AFTER DEBUG
}

const std::string& Weapon::getType()
{
	return(m_type);
}

void Weapon::setType(std::string type)
{
	m_type = type;
}