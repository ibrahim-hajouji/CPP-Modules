/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:06:44 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/16 16:23:30 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int value;
        static int const fractionalBits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif