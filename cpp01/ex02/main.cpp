/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:58:14 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/14 13:35:04 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN"; // The string variable
    std::string *stringPTR = &str; // Pointer to the string
    std::string &stringREF = str; // Reference to the string
    
    std::cout << std::endl << "------------------ Memory adresses : ------------------"<< std::endl << std::endl;
    std::cout << "The memory adress of the string variable : " << &str << std::endl;
    std::cout << "The memory adress held by stringPTR : " << stringPTR << std::endl;
    std::cout << "The memory adress held by stringREF : " << &stringREF << std::endl;

    std::cout << std::endl << "------------------ Memory adresses : ------------------"<< std::endl <<std::endl;
    std::cout << "The value of the string variable : " << str << std::endl;
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF : " << stringREF << std::endl << std::endl;
}