/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:16:12 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/12 03:12:35 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inv_slot[4];
        int used_slots;
        AMateria *unequiped_materia[4];
    public:
        Character();
        Character(const std::string &name);
        Character(const Character &src);
        Character   &operator=(const Character &src);
        ~Character();
        
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};


#endif