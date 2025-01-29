/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:40:49 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/23 13:40:18 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2 || av[1] != std::string("input.txt"))
    {
        std::cerr << "Usage: ./btc input.txt" << std::endl;
        return 1;
    }
    
    BitcoinExchange exchange;

    try
    {
        exchange.loadDatabase("data.csv");
        exchange.processInputFile(av[1]);
        
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}