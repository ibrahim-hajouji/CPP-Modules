/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 04:31:07 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/03 00:30:35 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = "Default Idea";
    }
    std::cout << "Brain Default constructor have been called" << std::endl;
}

Brain::Brain(const Brain &src)
{
    *this = src;
    std::cout << "Brain have been copied" << std::endl;
}

Brain   &Brain::operator=(const Brain &src)
{
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = src.ideas[i];
        }
    }
    std::cout << "Brain have been assigned" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain have been destructed" << std::endl;
}

const std::string &Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (ideas[index]);
    else
        return (ideas[0]);
}

void    Brain::setIdea(const std::string &idea, int index)
{
    if (index >= 0 && index < 100)
    {
        ideas[index] = idea;
    }
}
