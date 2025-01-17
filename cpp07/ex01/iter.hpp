/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:16:47 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/11 13:23:52 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    iter(T *array, int size, void (*func)(T &))
{
    for (int i = 0; i < size; i++)
        func(array[i]);
}

template <typename T>
void    print_(T &a)
{
    std::cout << a << std::endl;
}

#endif