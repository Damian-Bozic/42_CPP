/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:06:51 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/22 16:06:52 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/* deconstructor */
Base::~Base()
{

}

/* I'm forced to use dynamic_cast here since I've got to later
 find out what derived type the Base* actually points to. */
Base* Base::generate(void)
{
	srand(time(0));
	int i = rand() % 4;
	switch (i)
	{
		case 0:
		{
			A *child = new A;
			return (dynamic_cast<Base*>(child));
		}
		case 1:
		{
			B *child = new B;
			return (dynamic_cast<Base*>(child));
		}
		default:
		{
			C *child = new C;
			return (dynamic_cast<Base*>(child));
		}
	}
}

/* Dynamic_casts are great as they check type at run time (RTTI).
 This lets it fail at a bad cast, which we can use to find
 the derived type through brute force, like in this case. */
void Base::identify(Base* p)
{
	if (A* a = dynamic_cast<A*>(p))
	{
		(void)a;
		std::cout << "A" << std::endl;
	}
	else if (B* b = dynamic_cast<B*>(p))
	{
		(void)b;
		std::cout << "B" << std::endl;
	}
	else if (C* c = dynamic_cast<C*>(p))
	{
		(void)c;
		std::cout << "C" << std::endl;
	}
}

/* Here I have to use try catches as if statements only work
 with pointers. */
void Base::identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e) {}
}
