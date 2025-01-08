/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:25:55 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/31 05:25:55 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main ()
{
    try
    {
        Form f1("f1", 1, 0);
        std::cout << f1;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    try
    {
        Form f2("f2", 120, 120);
        std::cout << f2;
        Bureaucrat b1("b1", 1);
        std::cout << b1;
        b1.signForm(f2);
        std::cout << f2;
        Bureaucrat b2("b2", 150);
        f2.beSigned(b2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}