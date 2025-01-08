/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:09:40 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/30 23:14:04 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool isSigned; 
        const int sign_grade;
        const int execute_grade;
    public:
        Form();
        Form(const std::string name, const int sg, const int eg);
        Form(const Form &src);
        Form &operator=(const Form &src);
        ~Form();

        const std::string &getName() const;
        int getSGrade() const;
        int getEGrade() const;
        bool getSigned() const;
        void  beSigned(Bureaucrat &obj);  
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
};

std::ostream& operator<<(std::ostream &out, const Form& src);

#endif