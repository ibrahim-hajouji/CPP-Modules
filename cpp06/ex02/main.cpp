/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:38:34 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/11 09:46:08 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "B.hpp"

int main()
{
    srand(time(0));
    
    Base *base = generate();
    identify(base);
    identify(*base);
}