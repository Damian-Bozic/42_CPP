/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:43:09 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/07 19:43:10 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{	//		 		x	  y
	Point a = Point(1.5f, 2.5f);
	Point b = Point(5.25f, 7.75f);
	Point c = Point(8.5f, 3.25f);

	Point test_inside = Point(4.5f, 5.5f);				// Far inside
	Point test_outside = Point(0.75, 1.5);				// Far outside

	Point test_on_edge_a = Point(3.375f, 5.125f);		// On edge AB
	Point test_on_edge_b = Point(6.875f, 5.5f);			// On edge BC
	Point test_on_edge_c = Point(5.0f, 2.875f);			// On edge CA

	Point test_on_vertex_a = Point(1.5f, 2.5f);			// Vertex A
	Point test_on_vertex_b = Point(5.25f, 7.75f);		// Vertex B
	Point test_on_vertex_c = Point(8.5f, 3.25f);		// Vertex C

	Point test_close_outside_a = Point(3.375f, 5.126f);	// Slightly outside AB
	Point test_close_outside_b = Point(6.875f, 5.501f);	// Slightly outside BC
	Point test_close_outside_c = Point(5.0f, 2.874f);	// Slightly outside CA


std::cout << "test_inside: ";
if (bsp(a, b, c, test_inside))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_outside: ";
if (bsp(a, b, c, test_outside))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_on_edge_a: ";
if (bsp(a, b, c, test_on_edge_a))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_on_edge_b: ";
if (bsp(a, b, c, test_on_edge_b))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_on_edge_c: ";
if (bsp(a, b, c, test_on_edge_c))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_on_vertex_a: ";
if (bsp(a, b, c, test_on_vertex_a))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_on_vertex_b: ";
if (bsp(a, b, c, test_on_vertex_b))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_on_vertex_c: ";
if (bsp(a, b, c, test_on_vertex_c))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_close_outside_a: ";
if (bsp(a, b, c, test_close_outside_a))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_close_outside_b: ";
if (bsp(a, b, c, test_close_outside_b))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;

std::cout << "test_close_outside_c: ";
if (bsp(a, b, c, test_close_outside_c))
    std::cout << "Inside" << std::endl;
else
    std::cout << "Outside" << std::endl;
}