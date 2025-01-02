/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:09:40 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/01 06:25:21 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool isSigned;
        const int sign_grade;
        const int execute_grade;
    public:
        AForm();
        AForm(const std::string name, const int sg, const int eg);
        AForm(const AForm &src);
        AForm &operator=(const AForm &src);
        virtual ~AForm();

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        

        virtual void execute(Bureaucrat const & executor) const = 0;
        
};

std::ostream& operator<<(std::ostream &out, const AForm& src);

#endif