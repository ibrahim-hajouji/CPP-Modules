/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:25:07 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/17 11:36:51 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(42);
    
    try 
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "---------------" << std::endl;

    std::list <int> li;
    li.push_back(1);
    li.push_back(0);
    li.push_front(2);

    try
    {
        std::list<int>::iterator it = easyfind(li, 42);
        std::cout << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}