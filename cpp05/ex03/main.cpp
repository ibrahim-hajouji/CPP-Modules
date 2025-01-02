/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 04:36:59 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/02 22:05:37 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
    {
        Intern intern;
        Bureaucrat b1("b1", 1);
        try
        {
            AForm *f1 = intern.makeForm("Shrubbery Creation", "Tree");
            b1.signForm(*f1);
            b1.executeForm(*f1);
            delete f1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "-----------------------------------------------------------------------" << std::endl;

    {
        Intern intern;
        Bureaucrat b1("b1", 1);
        try
        {
            AForm *f1 = intern.makeForm("Non Existent Form", "Tree");
            b1.signForm(*f1);
            b1.executeForm(*f1);
            delete f1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
}