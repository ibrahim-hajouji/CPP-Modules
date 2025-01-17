/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:56:21 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/17 17:54:25 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iterating through the stack
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << "Stack elements:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "-----------------------------" << std::endl;


    std::list<int> mstack2;

    mstack2.push_back(5);
    mstack2.push_back(17);
    std::cout << "Top element: " << mstack2.back() << std::endl;

    mstack2.pop_back();
    std::cout << "Size after pop: " << mstack2.size() << std::endl;

    mstack2.push_back(3);
    mstack2.push_back(5);
    mstack2.push_back(737);
    mstack2.push_back(0);

    // Iterating through the list
    std::list<int>::iterator itt = mstack2.begin();
    std::list<int>::iterator itte = mstack2.end();

    ++itt;
    --itt;
    std::cout << "Stack elements:" << std::endl;
    while (itt != itte)
    {
        std::cout << *itt << std::endl;
        ++itt;
    }
    
    return 0;
}
