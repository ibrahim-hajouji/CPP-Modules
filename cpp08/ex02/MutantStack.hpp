/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:50:15 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/25 18:21:18 by ihajouji         ###   ########.fr       */
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
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        

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

        const_iterator begin() const
        {
            return (this->c.begin());
        }

        const_iterator end() const
        {
            return (this->c.end());
        }

        reverse_iterator rbegin() {
            return this->c.rbegin();
        }

        reverse_iterator rend() {
            return this->c.rend();
        }

        const_reverse_iterator rbegin() const {
            return this->c.rbegin();
        }

        const_reverse_iterator rend() const {
            return this->c.rend();
        }

};

#endif