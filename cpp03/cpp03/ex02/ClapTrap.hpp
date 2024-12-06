/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:19:34 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/24 03:54:29 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected :
        std::string name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;

    public :
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &src);
        ClapTrap    &operator=(const ClapTrap &src);
        ~ClapTrap();
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};


#endif