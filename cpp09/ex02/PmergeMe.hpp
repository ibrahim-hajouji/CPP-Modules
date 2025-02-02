/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:19:26 by marvin            #+#    #+#             */
/*   Updated: 2025/02/01 13:19:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <deque>
#include <exception>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        void validateInput(int ac, char **av);
        bool isPositiveInteger(const std::string &str);
        void fillContainers(int ac, char **av);
        void printContainers() const;
        void mergeInsertionSort(std::vector<int> &vec);
        void mergeInsertionSort(std::deque<int> &deq);

        std::deque<size_t>  generateInsertionOrder2(size_t size);
        std::vector<size_t> generateInsertionOrder(size_t size);
        std::vector<int> &getVec();
        std::deque<int> &getDeq();
};


#endif