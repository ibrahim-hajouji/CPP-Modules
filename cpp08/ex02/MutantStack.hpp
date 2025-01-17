/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:50:15 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/17 17:51:45 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        
        MutantStack() : std::stack<T>() 
        {
            
        }
        
        MutantStack(const MutantStack& src) : std::stack<T>(src)
        {
            
        }

        
        MutantStack &operator=(const MutantStack &src)
        {
            if (this != &src)
                std::stack<T>::operator=(src);
            return (*this);
        }
        
        ~MutantStack()
        {
            
        }

        iterator begin()
        {
            return (this->c.begin());
        }
        
        iterator end()
        {
            return (this->c.end());
        }
        
};

#endif