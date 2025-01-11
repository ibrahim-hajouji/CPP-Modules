/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:24:56 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/10 11:44:05 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &src);
        ~ScalarConverter();

        public:
            static void convert(std::string str);

};



#endif