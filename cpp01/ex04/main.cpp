/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:39:45 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/16 11:39:46 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string ft_replace(std::string buffer, std::string s1, std::string s2)
{
    std::string result;

    size_t pos = 0;
    size_t found_pos;

    if (s1.empty() || s2.empty())
        return (buffer);
    while ((found_pos = buffer.find(s1, pos)) != std::string::npos)
    {
        result.append(buffer, pos, found_pos - pos);
        result.append(s2);
        pos = found_pos + s1.length();
    }
    result.append(buffer, pos, buffer.length() - pos);
    return (result);
}

int main(int ac, char **av)
{
    std::string buffer;
    std::string new_buffer;
    if (ac != 4)
    {
        std::cout << "Usage: ./sed file old_str new_str" << std::endl;
        return (1);
    }
    std::ifstream infile(av[1]);
    if (infile.is_open() == 0)
    {
        std::cout << "File doesn't exist or you doesnt have the permission to open it" << std::endl;
        return (1);
    }
    std::string name;
    name.append(av[1]);
    name.append(".replace");
    std::ofstream outfile(name, std::ios::trunc);
    if (!outfile.is_open())
    {
        std::cout << "Error: Unable to create the output file." << std::endl;
        return (1);
    }

    getline(infile, buffer, '\0');
    new_buffer = ft_replace(buffer, av[2], av[3]);
    outfile << new_buffer;
    if (infile.peek() != EOF)   
        outfile << std::endl;
    infile.close();
    outfile.close();
}