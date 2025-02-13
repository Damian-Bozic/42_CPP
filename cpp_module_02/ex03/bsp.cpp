/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:43:51 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/07 19:43:52 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "iostream" // DEBUG

bool bsp(Point const a, Point const b, Point const c, Point const point)
{ // same side method formula
	float cross_1 = ((point.getX() - a.getX()) * (b.getY() - a.getY())
			- (point.getY() - a.getY()) * (b.getX() - a.getX()));
	float cross_2 = ((point.getX() - b.getX()) * (c.getY()- b.getY())
			- (point.getY() - b.getY()) * (c.getX() - b.getX())); 
	float cross_3 = ((point.getX() - c.getX()) * (a.getY()- c.getY())
			- (point.getY() - c.getY()) * (a.getX() - c.getX()));
	std::cout << cross_1 << " " << cross_2 << " " << cross_3 << " "; // DEBUG
	if (cross_1 >= 0 && cross_2 >= 0 && cross_3 >= 0)
		return (true);
	else if (cross_1 < 0 && cross_2 < 0 && cross_3 < 0)
		return (true);
	return (false);
}