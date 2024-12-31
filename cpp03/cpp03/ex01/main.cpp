/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:01:53 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/29 01:48:26 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Scavvy");
    scav.attack("enemy");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();
}