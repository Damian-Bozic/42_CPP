/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:43:46 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/07 19:43:46 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
 #define POINT_HPP

class Point
{
	private:
		const float x;
		const float y;

	public:
		Point();
		Point(float x, float y);
		Point(const Point &point);
		~Point();
		Point &operator = (const Point &point);
		float getX() const;
		float getY() const;
};

#endif