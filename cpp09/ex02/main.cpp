/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:27:09 by marvin            #+#    #+#             */
/*   Updated: 2025/02/01 13:27:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: " << av[0] << " [sequence of postive integers]" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    try
    {
        sorter.validateInput(ac, av);
        sorter.fillContainers(ac, av);

        std::cout << "Before: ";
        for (std::vector<int>::size_type i = 0; i < sorter.getVec().size(); i++)
        {
            std::cout << sorter.getVec()[i] << " ";
        }
        std::cout << std::endl;

        clock_t startVec = std::clock();
        sorter.mergeInsertionSort(sorter.getVec());
        clock_t endVec = std::clock();
        double timeVec = static_cast<double> (endVec - startVec) / CLOCKS_PER_SEC * 1000000;
        

        clock_t startDeq = std::clock();
        sorter.mergeInsertionSort(sorter.getDeq());
        clock_t endDeq = std::clock();
        double timeDeq = static_cast<double> (endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
        
        std::cout << "After:  ";
        for (std::vector<int>::size_type i = 0; i < sorter.getVec().size(); i++)
        {
            std::cout << sorter.getVec()[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Time to process a range of " << sorter.getVec().size() << " elements with std::vector : " << timeVec << " microseconds" << std::endl;
        std::cout << "Time to process a range of " << sorter.getDeq().size() << " elements with std::deque  : " << timeDeq << " microseconds" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}