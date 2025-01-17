/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:48:07 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/17 13:06:06 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
    private :
        unsigned int N;
        std::vector<int> vec;

    public :
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        Span &operator=(const Span &src);
        ~Span();
        
        void    addNumber(int nbr);
        int     shortestSpan();
        int     longestSpan();
        void    addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
    
};


#endif