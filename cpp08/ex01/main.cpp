/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:22:18 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/17 13:17:25 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try 
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    try 
    {
        Span sp = Span(3);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    std::vector<int> vec;
    for (int i = 0; i < 15000; i++)
        vec.push_back(i);
    Span    sp(15000);
    try
    {
        sp.addRange(vec.begin(), vec.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}