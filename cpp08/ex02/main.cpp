/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:56:21 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/25 18:37:33 by ihajouji         ###   ########.fr       */
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
    std::cout << "\033[33m" << "Top element: " << "\033[0m"  << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "\033[33m" << "Size after pop: " << "\033[0m"  << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iterating through the stack
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << "\033[33m" << "Stack elements: " << "\033[0m" ;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "\033[33m" "Stack elements (reverse): " << "\033[0m";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;
    
    std::cout << "-----------------------------------------" << std::endl;

    MutantStack<int> mstack2;
    std::cout << "\033[33m" << "Size of mstack2 before the copy: " << "\033[0m" << mstack2.size() << std::endl;
    mstack2 = mstack;
    std::cout << "\033[33m" << "Size of mstack2: after the copy: " << "\033[0m" << mstack2.size() << std::endl;
    std::cout << "\033[33m" << "Stack2 elements from the top: " << "\033[0m" ;
    while (!mstack2.empty()) {
        std::cout << mstack2.top() << " ";
        mstack2.pop();
    }
    std::cout << std::endl;

}