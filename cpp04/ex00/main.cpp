/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:37:35 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/30 22:09:04 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main ()
{
    {
        Dog d("Arya");
        d.makeSound();
        Cat c;
        c.makeSound();
    }
    {
        Animal* animal = new Cat("Whiskers");
        animal->makeSound();
        delete animal;
    }

}
