/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 03:55:06 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/02 21:52:38 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    this -> target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45)
{
    this -> target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
        this->target = src.target; 
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned())
    {
        if (executor.getGrade() <= this->getEGrade())
        {
            std::cout << "Drilling noises..." << std::endl;
            if (rand() % 2)
                std::cout << this->target << " has been robotomized successfully." << std::endl;
            else
                std::cout << this->target << " has failed to be robotomized." << std::endl;
        }
        else
            throw (AForm::GradeTooLowException());
    }
    else
        throw (AForm::FormNotSignedException());
}
