/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:55:26 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/01 06:25:00 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
    *this = src;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
        this->target = src.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned())
    {
        if (executor.getGrade() <= this->getEGrade())
        {
            std::ofstream target_file(this->target, std::ios::trunc);
            if (!target_file.is_open())
                throw (ShrubberyCreationForm::FileNotOpenedException());
            target_file << "                                  # #### ####\n";
            target_file << "                                ### \\/#|### |/####\n";
            target_file << "                               ##\\/#/ \\||/##/_/##/_#\n";
            target_file << "                             ###  \\/###|/ \\/ # ###\n";
            target_file << "                           ##_\\_#\\_\\## | #/###_/_####\n";
            target_file << "                          ## #### # \\ #| /  #### ##/##\n";
            target_file << "                           __#_--###`  |{,###---###-~\n";
            target_file << "                                     \\ }{\n";
            target_file << "                                      }}{\n";
            target_file << "                                      }}{\n";
            target_file << "                                      {{}}\n";
            target_file << "                                , -=-~{ .-^- _\n";
            target_file.close();
        }
        else
            throw (Bureaucrat::GradeTooLowException());
    }
    else
        throw (AForm::FormNotSignedException());
}

const char *ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
    return ("File could not be opened");
}

