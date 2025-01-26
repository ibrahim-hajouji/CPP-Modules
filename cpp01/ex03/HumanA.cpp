/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:32:05 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/16 09:31:29 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name) , weapon(weapon)
{
    std::cout << name << " joined the battle " << std::endl;
}

void    HumanA::attack()
{
    if (weapon.getType().length() == 0)
        std::cout << name << " has no weapon" << std::endl;
    else
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}