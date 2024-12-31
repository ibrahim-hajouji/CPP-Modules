/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:52:02 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/12 01:54:11 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class   Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const std::string &type);
        Animal(const Animal &src);
        Animal  &operator=(const Animal &src);
        virtual ~Animal();
        
        virtual void    makeSound() const = 0;
};

#endif