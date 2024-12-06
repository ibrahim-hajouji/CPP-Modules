/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:53:45 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/20 21:24:47 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
        
    public:
       Point();
       Point(const float x, const float y);
       Point(const Point &p);
       Point &operator=(const Point &p);
       ~Point();
       Fixed getX() const;
       Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const p);

#endif