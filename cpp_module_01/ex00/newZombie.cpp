/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:24:55 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/15 13:24:56 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// creates a zombie that is to be used outside of the functions scope
//  which means that heap allocation would be optimal for this.
Zombie *newZombie(std::string name)
{
	Zombie *new_zombie = new Zombie(name);

	return (new_zombie);
}
