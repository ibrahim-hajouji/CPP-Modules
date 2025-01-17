/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:15:06 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/11 16:31:35 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
    {
        Array<int> arr(5);
        
        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 10;
        
        for(unsigned i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        std::cout << arr[10] << std::endl;

        Array<int> arr2;
        arr2 = arr;
        
        for (unsigned int i = 0; i < arr2.size(); i++)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}