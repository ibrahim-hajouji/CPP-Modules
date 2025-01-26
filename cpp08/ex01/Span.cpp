/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:00:58 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/26 12:38:21 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    N = 0;
}

Span::Span(unsigned int N)
{
    this -> N = N;
}

Span::Span(const Span &src)
{
    *this = src;
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this -> N = src.N;
        this->vec = src.vec;
    }
    return (*this);
}

Span::~Span()
{
    
}

void    Span::addNumber(int nbr)
{
    if (this->vec.size() >= this->N)
        throw(std::runtime_error("No more space to add a number"));
    this->vec.push_back(nbr);
}

int Span::shortestSpan()
{
    if (this -> N <= 1)
        throw(std::runtime_error("Not enough numbers to calculate the span"));
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); i++)
    {
		if (tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
	}
    return (shortest);
}

int Span::longestSpan()
{
    if (this -> N <= 1)
        throw(std::runtime_error("Not enough numbers to calculate the span"));
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

void    Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (std::distance(start, end) + this->vec.size() > N)
        throw (std::runtime_error("No more space to add a number"));
    this->vec.insert(vec.end(), start, end);
}