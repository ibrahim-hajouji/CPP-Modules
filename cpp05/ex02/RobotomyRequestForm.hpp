/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 03:48:56 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/01 03:55:00 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotmyRequestForm : public AForm
{
    private:
        std::string target;
    
    public:
        RobotmyRequestForm();
        RobotmyRequestForm(const std::string &target);
        RobotmyRequestForm(const RobotmyRequestForm &src);
        RobotmyRequestForm &operator=(const RobotmyRequestForm &src);
        ~RobotmyRequestForm();
        
        void execute(Bureaucrat const & executor) const;
        
};

#endif