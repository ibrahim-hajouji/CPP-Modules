/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:30:18 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/10 14:37:03 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data
{
    int id;
    std::string login;
} Data;

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &src);
        ~Serializer();

        public:
            static uintptr_t serialize(Data *ptr);
            static Data *deserialize(uintptr_t raw);
};

#endif