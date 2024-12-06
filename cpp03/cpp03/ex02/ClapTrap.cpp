/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:26:18 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/29 21:28:17 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0)
{
    name = "Unnamed ClapTrap";
    std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << "Unnamed constructor is called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : hit_points(10), energy_points(10), attack_damage(0)
{
    this->name = name;
    std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->hit_points = src.hit_points;
        this->energy_points = src.energy_points;
        this->attack_damage = src.attack_damage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " Destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string  &target)
{
    if (!hit_points)
    {
        std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " tried to attack " << target << "  but couldn't due to lack of hit points" << std::endl;
        return;
    }
    else if (!energy_points)
    {
        std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " tried to attack " << target << "  but couldn't due to lack of energy points" << std::endl;
        return;
    }
    std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
    energy_points--;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points > amount)
    {
        hit_points -= amount;
        std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " took " << amount << " damage, now his health is at " << hit_points << std::endl; 
    }
    else if (hit_points > 0)
    {
        hit_points = 0;
        std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " took " << amount << " damage, and died."<< std::endl;         
    }
    else
        std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " is getting abused while he's dead." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!hit_points)
    {
        std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " tried to repair itself but couldn't due to lack of hit points" << std::endl;
        return;
    }
    else if (!energy_points)
    {
        std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " tried to repair itself but couldn't due to lack of energy points" << std::endl;
        return;
    }
    hit_points += amount;
    energy_points--;
    std::cout << "\033[31m" << "ClapTrap " << "\033[0m" << name << " repaired itself with " << amount << " hit points, now he have "<< hit_points << " hit points."<< std::endl;         
    
}