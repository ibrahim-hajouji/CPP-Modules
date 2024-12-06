/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:01:56 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/06 22:07:44 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("default"), inv_slot(), last_index(0)
{
    std::cout << "Character default has been constructed" << std::endl;
}

Character::Character (const std::string &name) : name(name), inv_slot(), last_index(0)
{
    std::cout << "Character " << name << " has been constructed" << std::endl;
}

Character::Character(const Character &src)
{
    *this = src;
    std::cout << "Character " << name << " has been copied" << std::endl; 
}

Character   &Character::operator=(const Character &src)
{
    this->name = src.name;
    this->last_index = src.last_index;
    for (int i = 0; i < 4; i++)
    {
        if(this->inv_slot[i])
            delete(this->inv_slot[i]);
        if (src.inv_slot[i])
            this->inv_slot[i] = src.inv_slot[i];
    }
    std::cout << "Character " << name << " has been assigned" << std::endl;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inv_slot[i])
            delete(this->inv_slot[i]);
        if (this->unequiped_materia[i])
            delete(this->unequiped_materia[i]);
    }
    std::cout << "Character " << name << " has been destroyed" << std::endl;
}

std::string const &Character::getName() const
{
    return (this->name);
}

void    Character::equip(AMateria *m)
{
    if (this->last_index >= 4 || !m)
        return;
    this->inv_slot[this->last_index] = m;
    std::cout << "Materia " << m->getType() << " has been equipped at the slot number " << this->last_index << std::endl;
    this->last_index++;
    if (this->last_index >= 4)
        this->last_index = 3;
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx > this->last_index || this->last_index == 0)
        return;
    if (this->inv_slot[idx])
    {
        unequiped_materia[idx] = this->inv_slot[idx];
        this->inv_slot[idx] = NULL;
        std::cout << "Materia " << unequiped_materia[idx]->getType() <<" has been unequipped from the slot number " << idx << std::endl;
        this->last_index--;
    }
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3)
        std::cout << "invalid index" << std::endl;
    else if (this->inv_slot[idx] == NULL)
        std::cout << "the slot " << idx << " is empty" << std::endl;
    else
    {
        this->inv_slot[idx]->use(target);
        std::cout << "Materia " << this->inv_slot[idx]->getType() << " has been used" << std::endl;
    }
}
