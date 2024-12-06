/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:39:59 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/12 09:47:01 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name)
{
    weapon = NULL;
    std::cout << name << " joined the battle " << std::endl;
}

void    HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
        
    else
       std::cout << name << " has no weapon" << std::endl; 
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
    std::cout << name << " has a new weapon: " << weapon.getType() << std::endl;
}