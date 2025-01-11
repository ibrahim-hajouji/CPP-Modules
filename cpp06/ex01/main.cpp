/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:39:45 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/10 14:45:42 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ()
{
    Data data;
    data.id = 8;
    data.login = "ihajouji";

    std::cout << "Data address before serialization: " << "\033[36m" << &data << "\033[0m" << std::endl;
    uintptr_t ptr = Serializer::serialize(&data);
    std::cout << "Serialized pointer: " << "\033[31m" << ptr << "\033[0m" << std::endl;
    Data *ptr2 = Serializer::deserialize(ptr);
    std::cout << "Data address after deserialization: " << "\033[32m" << ptr2 <<  "\033[0m" << std::endl;

}