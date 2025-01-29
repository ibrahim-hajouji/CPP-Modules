/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:54:51 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/27 16:24:55 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP

# define RPN_HPP

# include <iostream>
#include <stack>
#include <string>
#include <exception>

class RPN
{
    private:
        std::stack<double> _nbrs;
		double		_result;
            
    public:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        ~RPN();

        void    		calculate(std::string input);
        void			validateInput(std::string input);
		int     		isOperator(char c);
		static int		isSpace(char c);
		double			getResult() const;
};


#endif