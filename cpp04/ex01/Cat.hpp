/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:51:32 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/12 01:33:42 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal
{
    private:
        std::string name;
        Brain   *brain;
    public:
        Cat();
        Cat(const std::string &name);
        Cat(const Cat &src);
        Cat &operator=(const Cat &src);
        ~Cat();

        void    makeSound() const;
};

#endif