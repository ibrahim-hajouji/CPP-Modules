/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:01:27 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/20 21:32:12 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0) , y(0)
{
}

Point::Point(const float x, const float y) : x(Fixed(x)) , y(Fixed(y))
{
}

Point::Point(const Point &p) : x(p.x) , y(p.y)
{
}

Point   &Point::operator=(const Point &p)
{
    if (this == &p)
        return (*this);
    return (*this);
}

Point::~Point()
{
}

Fixed   Point::getX() const
{
    return x;
}

Fixed   Point::getY() const
{
    return y;
}

