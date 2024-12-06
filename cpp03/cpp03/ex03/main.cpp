/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:26:40 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/29 01:53:08 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt("ibrahim");
    
    std::cout << "Hit points: " << dt.getHitPoints() << std::endl;
    std::cout << "Energy points: " << dt.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << dt.getAttackDamage() << std::endl;
    
    dt.ScavTrap::attack("enemy");
    dt.whoAmI();

    dt.guardGate();
    dt.highFivesGuys();
}