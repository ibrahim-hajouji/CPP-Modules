/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:37:35 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/12 01:34:20 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main ()
{
    {   
        Animal *animals[6];
        for (int i = 0; i < 6; i++)
        {
            if (i % 2 == 0)
            {
                animals[i] = new Dog();
                if (!animals[i])
                {
                    std::cout << "Dog allocation have been failed" << std::endl;
                    exit(1);
                }
            }
            else
            {
                animals[i] = new Cat();
                if (!animals[i])
                {
                    std::cout << "Cat allocation have been failed" << std::endl;
                    exit(1);
                }
            }
        }

        std::cout << "--------------------------------------------" << std::endl;
        for (int i = 0; i < 6; i++)
        {
            animals[i]->makeSound();
        }

        std::cout << "--------------------------------------------" << std::endl;

        for (int i = 0; i < 6; i++)
        {
            delete animals[i];
        }
        
        std::cout << "--------------------------------------------" << std::endl;
        
        Dog *dog = new Dog();
        if (!dog)
        {
            std::cout << "Dog allocation have been failed" << std::endl;
            exit(1);
        }
        dog->_setIdea("I am sniffing the ground to find a bone", 0);
        dog->_setIdea("Ive run away from the owner", 99);
        std::cout << dog->_getIdea(0) << std::endl;
        std::cout << dog->_getIdea(99) << std::endl;
        
        std::cout << "--------------------------------------------" << std::endl;
        Dog *dog2 = new Dog(*dog);
        if (!dog2)
        {
            std::cout << "Dog2 allocation have been failed" << std::endl;
            exit(1);
        }
        std::cout << dog2->_getIdea(0) << std::endl;
        std::cout << dog2->_getIdea(99) << std::endl;
        delete dog;
        delete dog2;
    }
}