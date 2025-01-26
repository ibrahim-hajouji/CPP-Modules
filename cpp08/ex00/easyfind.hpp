/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:09:48 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/25 17:52:14 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T container, int val)
{
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    
    if (it == container.end())
        throw (std::runtime_error("Value not found"));
    
    return it;
}

#endif