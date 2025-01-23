/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:21:39 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/11 13:25:15 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int array[5] = {1, 2, 3};
    iter<int, int>(array, 3, print_);
    std::cout << "-----------------------------" << std::endl;
    
    std::string arr[3] = {"hello", "world", "!"};
    iter<std::string, std::string>(arr, 3, print_);
    
    return 0;
}
