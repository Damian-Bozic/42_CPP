/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:35:25 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/19 14:35:26 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
 #define DIAMONDTRAP_HPP
 #include "FragTrap.hpp"
 #include "ScavTrap.hpp"

//TODO
// fix the fact that this doesnt compile

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &scavTrap);
		~DiamondTrap();
		void attack(const std::string& target);
		// void takeDamage(unsigned int amount);
		// void beRepaired(unsigned int amount);
		void whoAmI();
};

#endif