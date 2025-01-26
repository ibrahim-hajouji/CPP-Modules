/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:31:11 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/16 09:25:27 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
    this->type = type;
}

const std::string &Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string type)
{
    this->type = type;
}
