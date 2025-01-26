/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:27:00 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/29 01:52:24 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("DefaultDT_clap_name")
{
    name = "DefaultDT";
    hit_points = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "\033[33m" << "DiamondTrap " << "\033[0m" << name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
    this->name = name;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "\033[33m" << "DiamondTrap " << "\033[0m" << name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout  << "\033[33m" <<  "DiamondTrap " << "\033[0m" << name << " copied." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap   &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->hit_points = src.hit_points;
        this->attack_damage = src.attack_damage;
        this->energy_points = src.energy_points;
    }
    std::cout << "\033[33m" <<  "DiamondTrap " << "\033[0m" << name << " assigned." << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[33m" << "DiamondTrap " << "\033[0m" << name << " destroyed." << std::endl;
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI( void )
{
    std::cout << "\033[33m" << "My DiamondTrap name is : " << "\033[0m" << this->name << std::endl;
    std::cout << "\033[31m" << "My ClapTrap name is " << "\033[0m" << ClapTrap::name << std::endl; 
}

unsigned int    DiamondTrap::getHitPoints()
{
    return (hit_points);
}

unsigned int    DiamondTrap::getEnergyPoints()
{
    return (energy_points);
}

unsigned int    DiamondTrap::getAttackDamage()
{
    return (attack_damage);
}
