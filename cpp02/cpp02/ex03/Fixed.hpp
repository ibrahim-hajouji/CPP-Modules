/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:42:21 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/19 22:42:23 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static int const fractionalBits = 8;
    
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const ;
        int toInt( void ) const ;
        bool    operator>(const Fixed &cp) const;
        bool    operator<(const Fixed &cp) const;
        bool    operator<=(const Fixed &cp) const;
        bool    operator>=(const Fixed &cp) const;
        bool    operator==(const Fixed &cp) const;
        bool    operator!=(const Fixed &cp) const;
        Fixed   operator+(const Fixed &cp) const;
        Fixed   operator-(const Fixed &cp) const;
        Fixed   operator*(const Fixed &cp) const;
        Fixed   operator/(const Fixed &cp) const;
        Fixed   &operator++();
        Fixed   &operator--();
        Fixed   operator++(int);
        Fixed   operator--(int);
        static Fixed &min(Fixed &n1, Fixed &n2);
        static Fixed &max(Fixed &n1, Fixed &n2);
        const static Fixed &min(const Fixed &n1,const Fixed &n2);
        const static Fixed &max(const Fixed &n1,const Fixed &n2);
        
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif