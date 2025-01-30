/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:24:46 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/15 13:24:47 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie::Zombie(std::string name)
// {
// 	m_name = name;
// }

Zombie::Zombie()
{
	m_name = "";
}

Zombie::~Zombie()
{
	std::cout << m_name << " has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << m_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	m_name = name;
}
