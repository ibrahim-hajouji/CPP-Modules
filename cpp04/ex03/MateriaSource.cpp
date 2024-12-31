/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:41:45 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/06 05:09:25 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : inventory()
{
    std::cout << "MateriaSource has been constructed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    *this = src;
    std::cout << "Material has been copied" << std::endl;
}

MateriaSource   &MateriaSource::operator=(const MateriaSource &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete (this->inventory[i]);
        if (src.inventory[i])
            this->inventory[i] = src.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    std::cout << "MateriaSource has been assigned" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete (this->inventory[i]);
    }
    std::cout << "MateriaSource has been deconstructed" << std::endl;
}

void    MateriaSource::learnMateria(AMateria *mat)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = mat;
            std::cout << "Materia " << mat->getType() << " has been learned at the slot number " << i << std::endl;
            break;
        }
    }
}

AMateria    *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] && this->inventory[i]->getType() == type)
        {
            std::cout << "Materia " << type << " has been created" << std::endl;
            return (this->inventory[i]->clone());
        }
    }
    return (NULL);
}