/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:10:50 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/20 21:39:52 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Fixed   areaOf(Point const a, Point const b, Point const c)
{
    Fixed result = ((a.getX() * (b.getY() - c.getY()) + 
                     b.getX() * (c.getY() - a.getY()) + 
                     c.getX() * (a.getY() - b.getY())).toFloat() / 2.0f);

    if (result < 0)
        result = result * -1;
    return (result);
}

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
    Fixed mainArea = areaOf(a, b, c);
    Fixed areaABP = areaOf(a, b, p);
    Fixed areaBCP = areaOf(b, c, p);
    Fixed areaCAP = areaOf(c, a, p);
    if (areaABP > 0 && areaBCP > 0 && areaCAP > 0 && (areaABP + areaBCP + areaCAP == mainArea))
        return (true);
    return (false); 
}