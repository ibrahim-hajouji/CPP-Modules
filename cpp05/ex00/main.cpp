/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:47:25 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/30 22:31:49 by ihajouji         ###   ########.fr       */
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
        Bureaucrat b("imane", 150);
        std::cout << b;
        b.decrementGrade();
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}