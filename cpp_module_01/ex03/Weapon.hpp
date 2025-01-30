/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:23:08 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/17 18:23:09 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
 #define WEAPON_HPP
 #include <string>

class Weapon
{
	private:
		std::string m_type;

	public:
		Weapon(std::string weapon);
		~Weapon();
		const std::string &getType();
		void setType(std::string type);
};

#endif