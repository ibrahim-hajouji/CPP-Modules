/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 04:08:36 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/26 02:29:32 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap frag("fragy");
    frag.highFivesGuys();
    frag.attack("enemy");
    frag.takeDamage(90);
    frag.takeDamage(10);
    frag.takeDamage(10);
}