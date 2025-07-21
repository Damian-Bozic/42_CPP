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

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// TODO fix non-const Animals

int main()
{
	std::cout << "\n---=== ANIMAL ===---\n" << std::endl;
	Animal* meta = new Animal();
	Animal* i = new Dog();
	Animal* j = new Cat();
	Animal* k = j;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "\n---=== WRONG ANIMAL ===---\n" << std::endl;
	WrongAnimal* wmeta = new WrongAnimal();
	WrongAnimal* wi = new WrongCat();
	WrongAnimal* wj = wi;
	std::cout << wi->getType() << " " << std::endl;
	std::cout << wj->getType() << " " << std::endl;
	wi->makeSound(); //will output the cat sound!
	wj->makeSound();
	wmeta->makeSound();
	delete wmeta;
	delete wi;

	std::cout << "\n---=== CONST ANIMAL ===---\n" << std::endl;
	const Animal* cmeta = new Animal();
	const Animal* ci = new Dog();
	const Animal* cj = new Cat();
	const Animal* ck = cj;
	std::cout << ci->getType() << " " << std::endl;
	std::cout << cj->getType() << " " << std::endl;
	std::cout << ck->getType() << " " << std::endl;
	ci->makeSound(); //will output the cat sound!
	cj->makeSound();
	ck->makeSound();
	cmeta->makeSound();
	delete cmeta;
	delete cj;
	delete ci;

	std::cout << "\n---=== CONST WRONG ANIMAL ===---\n" << std::endl;
	const WrongAnimal* cwmeta = new WrongAnimal();
	const WrongAnimal* cwi = new WrongCat();
	const WrongAnimal* cwj = cwi;
	std::cout << cwi->getType() << " " << std::endl;
	std::cout << cwj->getType() << " " << std::endl;
	cwi->makeSound(); //will output the cat sound!
	cwj->makeSound();
	cwmeta->makeSound();
	delete cwmeta;
	delete cwi;
	return 0;
}
