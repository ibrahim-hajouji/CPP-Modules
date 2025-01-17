/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:04:16 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/11 13:11:14 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T   min(T &a, T &b)
{
    return (a < b ? a : b);
}

template <typename T>
T   max(T &a, T &b)
{
    return (a > b ? a : b);
}


#endif