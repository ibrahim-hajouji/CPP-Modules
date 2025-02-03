/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:36:07 by marvin            #+#    #+#             */
/*   Updated: 2025/02/01 13:36:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->vec = src.vec;
        this->deq = src.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

bool    PmergeMe::isPositiveInteger(const std::string &str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (i == 0 && str[i] == '+' && str.length() > 1)
            continue;

        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

void PmergeMe::validateInput(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        if (!isPositiveInteger(arg) || std::atol(av[i]) > INT_MAX)
        {
            throw std::invalid_argument("Error: Invalid input. All arguments must be positive integers.");
        }
    }
}

void PmergeMe::fillContainers(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        int num = std::atoi(av[i]);

        vec.push_back(num);
        deq.push_back(num);
    }
}

void PmergeMe::mergeInsertionSort(std::vector<int> &vec)
{
    // Base case: If array has 1 or 0 elements, it's already sorted
    if (vec.size() < 2)
        return;

    // Step 1: Create pairs of elements and sort each pair
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> pend;    // Elements that will be inserted later
    std::vector<int> mainSeq; // Holds the larger elements of each pair

    for (size_t i = 0; i < vec.size() - 1; i += 2)
    {
        if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]); // Sort pair
        
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }

    // Step 2: Extract the larger elements into `mainSeq` and smaller ones into `pend`
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainSeq.push_back(pairs[i].second); // Larger number
        pend.push_back(pairs[i].first);     // Smaller number
    }

    // If odd number of elements, last one goes into pend
    if (vec.size() % 2 != 0)
        pend.push_back(vec.back());

    // Step 3: Recursively sort mainSeq
    mergeInsertionSort(mainSeq);

    // Step 4: Generate insertion order for `pend` elements
    std::vector<size_t> insertOrder = generateInsertionOrder(pend.size());

    // Step 5: Insert elements from `pend` into `mainSeq` using binary insertion
    for (size_t i = 0; i < insertOrder.size(); i++)
    {
        if (insertOrder[i] < pend.size())
        {
            // Find correct insertion position using binary search (lower_bound)
            std::vector<int>::iterator pos = std::lower_bound(mainSeq.begin(), mainSeq.end(), pend[insertOrder[i]]);
            mainSeq.insert(pos, pend[insertOrder[i]]);
        }
    }

    // Copy sorted values back to `vec`
    vec = mainSeq;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t size)
{
    std::vector<size_t> order;
    if (size == 0)
        return order;

    // Step 1: Start with index 0
    order.push_back(0);
    
    // Step 2: Insert numbers following powers of 2 (1, 2, 4, 8, ...)
    size_t next = 1;
    while (next < size)
    {

        order.push_back(next);
        
        if (next * 2 < size)
            next *= 2;
        
        else
            next = size; // Stop if exceeding size
    }

    // Step 3: Fill in missing numbers in order
    for (size_t i = 1; i < size; i++)
    {
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    }
    
    return order;
}


void    PmergeMe::mergeInsertionSort(std::deque<int> &deq)
{
    if (deq.size() < 2)
        return;

    // Step 1: Create pairs of elements and sort each pair
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> pend;    // Elements that will be inserted later
    std::deque<int> mainSeq; // Holds the larger elements of each pair

    for (size_t i = 0; i < deq.size() - 1; i += 2)
    {
        if (deq[i] > deq[i + 1])
            std::swap(deq[i], deq[i + 1]); // Sort pair
        
        pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }

    // Step 2: Extract the larger elements into `mainSeq` and smaller ones into `pend`
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainSeq.push_back(pairs[i].second); // Larger number
        pend.push_back(pairs[i].first);     // Smaller number
    }

    // If odd number of elements, last one goes into pend
    if (deq.size() % 2 != 0)
        pend.push_back(deq.back());

    // Step 3: Recursively sort mainSeq
    mergeInsertionSort(mainSeq);

    // Step 4: Generate insertion order for `pend` elements
    std::deque<size_t> insertOrder = generateInsertionOrder2(pend.size());

    // Step 5: Insert elements from `pend` into `mainSeq` using binary insertion
    for (size_t i = 0; i < insertOrder.size(); i++)
    {
        if (insertOrder[i] < pend.size())
        {
            // Find correct insertion position using binary search (lower_bound)
            std::deque<int>::iterator pos = std::lower_bound(mainSeq.begin(), mainSeq.end(), pend[insertOrder[i]]);
            mainSeq.insert(pos, pend[insertOrder[i]]);
        }
    }

    // Copy sorted values back to `deq`
    deq = mainSeq;
}

std::deque<size_t> PmergeMe::generateInsertionOrder2(size_t size)
{
    std::deque<size_t> order;
    if (size == 0)
        return order;

    // Step 1: Start with index 0
    order.push_back(0);
    
    // Step 2: Insert numbers following powers of 2 (1, 2, 4, 8, ...)
    size_t next = 1;
    while (next < size)
    {
        order.push_back(next);

        if (next * 2 < size)
            next *= 2;
        
        else
            next = size; // Stop if exceeding size
    }

    // Step 3: Fill in missing numbers in order
    for (size_t i = 1; i < size; i++)
    {
        if (std::find(order.begin(), order.end(), i) == order.end()) {
            order.push_back(i);
        }
    }
    
    return order;
}



std::vector<int> &PmergeMe::getVec()
{
    return vec;
}

std::deque<int> &PmergeMe::getDeq()
{
    return deq;
}


void PmergeMe::printContainers() const
{

    for (std::vector<int>::size_type i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    for (std::deque<int>::size_type i = 0; i < deq.size(); i++)
    {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;

}