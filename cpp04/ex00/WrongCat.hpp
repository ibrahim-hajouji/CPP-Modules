/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:46:44 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/30 23:48:04 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal
{
    private:
        std::string name;
    public:
        WrongCat();
        WrongCat(const std::string &name);
        WrongCat(const WrongCat &src);
        WrongCat &operator=(const WrongCat &src);
        ~WrongCat();

        void    makeSound();
};

#endif