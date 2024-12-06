/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:44:00 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/29 01:45:55 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    name = "Default";
    std::cout << "\033[32m" << "ScavTrap " << "\033[0m" << name << " constructed." << std::endl;
}


ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "\033[32m" << "ScavTrap " << "\033[0m" << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    *this = src;
    std::cout << "\033[32m" << "ScavTrap " << "\033[0m" << name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    if (this != &src)
        ClapTrap::operator=(src);
    std::cout << "\033[32m" << "ScavTrap " << "\033[0m" << name << " assigned." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[32m" << "ScavTrap " << "\033[0m" << name << " destroyed." << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
    if (!hit_points)
    {
        std::cout << "\033[32m" << "ScavTrap " << "\033[0m" << name << " tried to attack " << target << "  but couldn't due to lack of hit points" << std::endl;
        return;
    }
    else if (!energy_points)
    {
        std::cout << "\033[32m" << "ScavTrap " << "\033[0m" << name << " tried to attack " << target << "  but couldn't due to lack of energy points" << std::endl;
        return;
    }
    std::cout << "\033[32m" << "ScavTrap " << "\033[0m" << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
    energy_points--;
    return ;
}

void    ScavTrap::guardGate()
{
    std::cout << "\033[32m" << "ScavTrap " << "\033[0m" << name << " is now in Gate keeper mode." << std::endl;
}
