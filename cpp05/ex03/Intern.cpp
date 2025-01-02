/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:57:50 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/02 22:03:42 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}

Intern::~Intern()
{
}

static  AForm *createShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

static  AForm *createRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static  AForm *createPresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string name, std::string target)
{

    AForm *form = NULL;
    
    AForm *(*form_functs[3])(std::string target) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    std::string form_names[3] = { "Shrubbery Creation", "Robotomy Request", "Presidential Pardon" };

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        if (name == form_names[i])
        {
            form = form_functs[i](target);
            std::cout << "Intern creates " << *form;
            return (form);
        }
    }
    throw (Intern::FormNotFoundException());
    return (NULL);
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}