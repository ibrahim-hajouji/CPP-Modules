/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:47:25 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/08 07:27:44 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("ibrahim", 1);
        std::cout << a;
        a.incrementGrade();
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("imane", 151);
        std::cout << b;
        b.decrementGrade();
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}