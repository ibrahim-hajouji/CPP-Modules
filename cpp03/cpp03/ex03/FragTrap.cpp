/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:56:31 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/26 01:59:10 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "\033[34m" << "FragTrap " << "\033[0m" << name << " constructed." << std::endl;
}


FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "\033[34m" << "FragTrap " << "\033[0m" << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    *this = src;
    std::cout << "\033[34m" << "FragTrap " << "\033[0m" << name << " copied." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    if (this != &src)
        ClapTrap::operator=(src);
    std::cout << "\033[34m" << "FragTrap " << "\033[0m" << name << " assigned." << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "\033[34m" << "FragTrap " << "\033[0m" << name << " destroyed." << std::endl;
}

void    FragTrap::highFivesGuys( void )
{
    std::cout << "\033[34m" << "FragTrap " << "\033[0m" << name << " says: High five, guys!" << std::endl;
}