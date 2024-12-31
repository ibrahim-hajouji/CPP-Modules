/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:29:20 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/29 01:30:54 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &src);
        ScavTrap    &operator=(const ScavTrap &src);
        ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};



#endif