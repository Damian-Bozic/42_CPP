/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:23:45 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/17 18:23:47 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
 #define HUMANB_HPP
 #include <string>
 #include <iostream>
 #include "Weapon.hpp"

// We set the weapon as a pointer, then point to a reference
//  later on

class HumanB
{
	private:
		std::string	m_name;
		Weapon		*m_weapon;

	public:
		HumanB(const char *name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif
