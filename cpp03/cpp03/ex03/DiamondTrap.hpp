/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:27:16 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/29 01:39:42 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
    private:
        std::string name;
    
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &src);
        DiamondTrap     &operator=(const DiamondTrap &src);
        ~DiamondTrap();

        void    attack(const std::string &target);
        void    whoAmI();
        unsigned int    getHitPoints();
        unsigned int    getEnergyPoints();
        unsigned int    getAttackDamage();

};

#endif