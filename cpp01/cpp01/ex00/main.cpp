/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:13:46 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/16 11:25:13 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "--------- Stack Zombies : ---------" << std::endl;
    {
        Zombie zombie1("zombie1");
        Zombie zombie2("zombie2");
        Zombie zombie3;

        zombie1.announce();
        zombie2.announce();
        zombie3.announce();
        randomChump("random Zombie");
        randomChump("");
    }

    std::cout << std::endl;
    std::cout << "--------- Heap Zombies : ---------" << std::endl;
    Zombie *zombie4 = newZombie("zombie4");
    if (!zombie4)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (1);
    }
    zombie4->announce();
    Zombie *zombie5 = newZombie("zombie5");
    if (!zombie5)
    {
        std::cout << "Memory allocation failed" << std::endl;
        delete(zombie4);
        return (1);
    }
    zombie5->announce();
    delete(zombie4);
    delete(zombie5);
    return (0);
}