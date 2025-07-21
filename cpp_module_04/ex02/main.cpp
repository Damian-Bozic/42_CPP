/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:08:06 by dbozic            #+#    #+#             */
/*   Updated: 2025/06/05 12:08:07 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "\n---=== Start of main ===---\n" << std::endl;

	// Animal bobbery;
/* 	main.cpp:22:9: error: variable type 'Animal' is an abstract class
        Animal bobbery;
               ^ */
	Animal *cheddar = new Cat();
	std::cout << cheddar->getType() << std::endl;	

	std::cout << "\n---=== End of main ===---\n" << std::endl;
}
