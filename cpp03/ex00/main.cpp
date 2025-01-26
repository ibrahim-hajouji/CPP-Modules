/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:06:41 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/29 01:40:48 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
    ClapTrap c1("ibrahim");
    c1.attack("hitler");
    c1.takeDamage(5);
    c1.beRepaired(10);
    c1.takeDamage(20);
    c1.attack("trump");
}