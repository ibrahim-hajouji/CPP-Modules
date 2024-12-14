/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:40:17 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/12 01:12:07 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class   Dog : public Animal
{
    private:
        std::string name;
    public:
        Dog();
        Dog(const std::string &name);
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        ~Dog();

        void    makeSound() const;
};

#endif
