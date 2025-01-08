/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:22:28 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/08 07:58:01 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
      std::string target;
    public:
      ShrubberyCreationForm();
      ShrubberyCreationForm(const std::string &target);
      ShrubberyCreationForm(const ShrubberyCreationForm &src);
      ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
      ~ShrubberyCreationForm();

      void execute(Bureaucrat const & executor) const;

      class FileNotOpenedException : public std::exception
      {
          public:
              virtual const char* what() const throw();
      };
        
};

#endif