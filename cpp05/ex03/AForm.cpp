/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:25:50 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/01 03:47:20 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), sign_grade(150), execute_grade(150)
{
    isSigned = false;
}

AForm::AForm(const std::string name, const int sg, const int eg): _name(name) , sign_grade(sg), execute_grade(eg)
{
    if (sg > 150 || eg > 150)
        throw (AForm::GradeTooLowException());
    else if (sg < 1 || eg < 1)
        throw (AForm::GradeTooHighException());
    isSigned = false;
}

AForm::AForm(const AForm &src): _name(src.getName()), sign_grade(src.getSGrade()), execute_grade(src.getEGrade())
{
    *this = src;
}

AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
    {
        this -> isSigned = src.getSigned();
    }
    return (*this);
}

AForm::~AForm()
{
    
}

const std::string &AForm::getName() const
{
    return (this->_name);
}

int AForm::getSGrade() const
{
    return (this->sign_grade);
}

int AForm::getEGrade() const
{
    return (this->execute_grade);
}

bool AForm::getSigned() const
{
    return (this->isSigned);
}

void AForm::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > this->sign_grade)
        throw (AForm::GradeTooLowException());
    this->isSigned = true;
    std::cout << this->_name << " has been signed by " << obj.getName() << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

std::ostream& operator<<(std::ostream &out, const AForm& src)
{
    out << "AForm " << src.getName() << " is ";
    if (src.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << src.getSGrade() << " to sign and grade " << src.getEGrade() << " to execute" << std::endl;
    return (out);
}

