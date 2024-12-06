/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:48:55 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/10 12:36:31 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "Unnamed Zombie";
}

Zombie::Zombie(std::string name)
{
	if (name.empty())
		this->name = "Unnamed Zombie";
	else
		this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << name << " is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
