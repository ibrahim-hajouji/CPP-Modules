/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:27:32 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/20 22:53:09 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point inside(1, 1);
    Point outside(6, 6);
    Point onEdge(2.5, 0);

    std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl; // Expected: true
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl; // Expected: false
    std::cout << "On Edge: " << bsp(a, b, c, onEdge) << std::endl; // Expected: false

    return 0;
}
