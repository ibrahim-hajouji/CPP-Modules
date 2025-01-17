/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:56:11 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/11 16:28:18 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    
    public:
        Array()
        {
            _array = NULL;
            _size = 0;
        }
        
        Array(unsigned int n)
        {
            _array = new T[n];
            _size = n;
        }
        
        Array(const Array<T>& src)
        {
            _array = new T[src.size()];
            _size = src.size();
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = src[i];
        }

        Array<T>& operator=(const Array<T>& src)
        {
            if (this != &src)
            {
                if (_array)
                    delete[] _array;
                _array = new T[src.size()];
                _size = src.size();
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = src[i];
            }
            return *this;
        }
        
        ~Array()
        {
            if (_array)
                delete[] _array;
        }

        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }
        
        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }
        
        unsigned int size() const
        {
            return _size;
        }
};



#endif