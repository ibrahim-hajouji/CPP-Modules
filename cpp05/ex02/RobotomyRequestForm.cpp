/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 03:55:06 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/01 04:21:44 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm() : AForm("RobotmyRequestForm", 72, 45)
{
    this -> target = "default";
}

RobotmyRequestForm::RobotmyRequestForm(const std::string &target) : AForm("RobotmyRequestForm", 72, 45)
{
    this -> target = target;
}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &src)
{
    *this = src;
}

RobotmyRequestForm &RobotmyRequestForm::operator=(const RobotmyRequestForm &src)
{
    if (this != &src)
        this->target = src.target; 
    return (*this);
}

RobotmyRequestForm::~RobotmyRequestForm()
{
    
}

void    RobotmyRequestForm::execute(Bureaucrat const & executor) const
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
