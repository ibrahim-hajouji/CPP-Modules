/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:32:28 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/16 11:31:34 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (int ac, char **av)
{
    Zombie *Horde;
    if (ac < 3)
    {
        std::cout << "Usage: ./ZombieHorde [number of zombies] [name]" << std::endl;
        return (1);
    }
    try
    {
        std::stoi(av[1]);
    }
    catch (std::out_of_range &e)
    {
        std::cout << "the number must be an integer" << std::endl;
        return (1);
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "the argument must be an integer" << std::endl;
        return (1);
    }
    if (std::stoi(av[1]) <= 0)
    {
        std::cout << "the number of zombies must be positive" << std::endl;
        return (1);
    }
    
    Horde = zombieHorde(std::stoi(av[1]),av[2]);
    if (!Horde)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (1);
    }
    for (int i = 0; i < std::atoi(av[1]); i++)
        Horde[i].announce();
    
    delete [] Horde;
    std::cout << std::atoi(av[1]) << " Zombies have been killed" << std::endl;
    return (0);
    
}