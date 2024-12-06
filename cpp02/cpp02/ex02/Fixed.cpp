/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:22:12 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/22 00:53:16 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"  

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value << fractionalBits;
}

Fixed::Fixed( float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->value = src.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)value / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
    return value >> fractionalBits;
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed_nbr)
{
	return (out << fixed_nbr.toFloat());
}

bool    Fixed::operator>(const Fixed &cp) const
{
    if (this->value > cp.value)
        return (true);
    return (false);
}

bool    Fixed::operator<(const Fixed &cp) const
{
    if (this->value < cp.value)
        return (true);
    return (false);
}

bool    Fixed::operator<=(const Fixed &cp) const
{
    if (this->value <= cp.value)
        return (true);
    return (false);
}

bool    Fixed::operator>=(const Fixed &cp) const
{
    if (this->value >= cp.value)
        return (true);
    return (false);
}

bool    Fixed::operator==(const Fixed &cp) const
{
    if (this->value == cp.value)
        return (true);
    return (false);
}

bool    Fixed::operator!=(const Fixed &cp) const
{
    if (this->value != cp.value)
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed &cp) const
{
    return Fixed(this->toFloat() + cp.toFloat());
}

Fixed Fixed::operator-(const Fixed &cp) const
{
    return Fixed(this->toFloat() - cp.toFloat());
}

Fixed Fixed::operator*(const Fixed &cp) const
{
    return Fixed(this->toFloat() * cp.toFloat());
}

Fixed Fixed::operator/(const Fixed &cp) const
{
    return Fixed(this->toFloat() / cp.toFloat());
}

Fixed   &Fixed::operator++()
{
    this->value++;
    return (*this);
}

Fixed   &Fixed::operator--()
{
    this->value--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   tmp = *this;
    this->value++;
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->value--;
    return (tmp);
}

Fixed   &Fixed::min(Fixed &n1, Fixed &n2)
{
    if (n1.value < n2.value)
        return (n1);
    else
        return (n2);
} 
Fixed   &Fixed::max(Fixed &n1, Fixed &n2)
{
    if (n1.value > n2.value)
        return (n1);
    else
        return (n2);
} 
const Fixed   &Fixed::min(const Fixed &n1, const Fixed &n2)
{
    if (n1.value < n2.value)
        return (n1);
    else
        return (n2);
} 
const Fixed   &Fixed::max(const Fixed &n1, const Fixed &n2)
{
    if (n1.value > n2.value)
        return (n1);
    else
        return (n2);
} 