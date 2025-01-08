/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:08:25 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/08 09:15:04 by ihajouji         ###   ########.fr       */
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

void Bureaucrat::signForm(AForm &obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << this->_name << " signs " << obj.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " cannot sign " << obj.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << this->getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
    return (out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl);
}
