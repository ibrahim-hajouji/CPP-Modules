/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 04:19:36 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/01 04:28:31 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
    *this = src;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src)
        this -> target = src.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned())
    {
        if (executor.getGrade() <= this->getEGrade())
        {
            std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
        }
        else
            throw(AForm::GradeTooLowException());
    }
    else
        throw(AForm::FormNotSignedException());
}
