/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:15:29 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/22 04:39:18 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2));
    int dif;
    std::cout << "-------------  <= comparison  -------------" << std::endl;
    dif = a <= b;
    std::cout << dif << std::endl;
    std::cout << "-------------  < comparison  -------------" << std::endl;
    dif = a < b;
    std::cout << dif << std::endl;
    std::cout << "-------------  >= comparison  -------------" << std::endl;
    dif = a >= b;
    std::cout << dif << std::endl;
    std::cout << "-------------  > comparison  -------------" << std::endl;
    dif = a > b;
    std::cout << dif << std::endl;
    std::cout << "-------------  == comparison  -------------" << std::endl;
    dif = a == b;
    std::cout << dif << std::endl;
    std::cout << "-------------  != comparison  -------------" << std::endl;
    dif = a != b;
    std::cout << dif << std::endl;
    std::cout << "-------------  * operation  -------------" << std::endl;
    std::cout << b * Fixed(2) << std::endl;
    std::cout << "-------------  + operation  -------------" << std::endl;
    std::cout << b + Fixed(2) << std::endl;
    std::cout << "-------------  - operation  -------------" << std::endl;
    std::cout << b - Fixed(2) << std::endl;
    std::cout << "-------------  / operation  -------------" << std::endl;
    std::cout << b / Fixed(2) << std::endl;
    std::cout << "-------------  pre-increment  -------------" << std::endl;
    std::cout << "a = " << ++a << std::endl;
    std::cout << "-------------  post-increment  -------------" << std::endl;
    std::cout << "a = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "-------------  pre-decrement  -------------" << std::endl;
    std::cout << "a = " << --a << std::endl;
    std::cout << "-------------  post-decrement  -------------" << std::endl;
    std::cout << "a = " << a-- << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "-------------  Minimum  -------------" << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    std::cout << "-------------  Maximum  -------------" << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    
}