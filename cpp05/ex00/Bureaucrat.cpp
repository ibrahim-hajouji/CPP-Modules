/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:47:30 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/08 07:09:34 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
    *this = src;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
    {
        this -> _grade = src.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    
}

const std::string &Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw(Bureaucrat::GradeTooLowException());
    this->_grade++;
}

void    Bureaucrat::incrementGrade()
{
    if (this -> _grade == 1)
        throw(Bureaucrat::GradeTooHighException());
    this->_grade--;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too Low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
    return (out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl);
}
