/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:26:33 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/03 00:30:03 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
       std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &src);
        Brain   &operator=(const Brain &src);
        ~Brain();

        const std::string &getIdea(int index) const;        
        void    setIdea(const std::string &idea, int index);
};

#endif
