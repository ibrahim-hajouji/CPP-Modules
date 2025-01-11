/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:24:34 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/11 09:44:55 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base *generate(void)
{
    int random = rand() % 3;

    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
    else
        std::cout << "Unknown class" << std::endl;
}

void    identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Class A" << std::endl;
        return;
    }
    catch (std::bad_cast &)
    {
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Class B" << std::endl;
        return;
    }
    catch (std::bad_cast &)
    {
    }
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Class C" << std::endl;
        return;
    }
    catch (std::bad_cast &)
    {
    }

    
}