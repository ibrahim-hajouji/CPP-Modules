/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:52:22 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/10 12:29:07 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

int is_nbr_dotted(std::string str)
{
    if (str.empty() || (((str[0] == '-' || str[0] == '+' || str[0] == '.')) && str.length() == 1))
        return 0;
    if (str[0] == '-' || str[0] == '+')
        str = str.substr(1, str.length());
    int dot = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            dot++;
        if (!std::isdigit(str[i]) && str[i] != '.')
            return 0;
    }
    if (dot != 1)
        return 0;
    return 1;
}

std::string detectType(std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return "char";
    else if (str == "+inff" || str == "-inff")
        return "inff";
    else if (str == "nanf")
        return "nanf";
    else if (str == "+inf" || str == "-inf")
        return "inf";
    else if (str == "nan")
        return "nan";
    else if (std::all_of(str.begin(), str.end(), ::isdigit))
        return "int";
    else if (str.back() == 'f' && is_nbr_dotted(str.substr(0, str.length() - 1)))
        return "float";
    else if (is_nbr_dotted(str.substr(0, str.length())))
        return "double";

    return "unknown";
}

void    convertChar(std::string str)
{
    char c = str[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void    convertInt(std::string str)
{
    int i = std::stoi(str);
    
    char c = static_cast<char>(i);
    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    std::cout << "int: " << i << std::endl;

    float f = static_cast<float>(i);
    std::cout << "float: " << f << "f" << std::endl;

    double d = static_cast<double>(i);
    std::cout << "double: " << d << std::endl;
    
}

void    convertFloat(std::string str)
{
    float f = std::stof(str);
    
    char c = static_cast<char>(f);
    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    int i = static_cast<int>(f);
    std::cout << "int: " << i << std::endl;

    std::cout << "float: " << f << "f" << std::endl;

    double d = static_cast<double>(f);
    std::cout << "double: " << d << std::endl;
}

void    convertDouble(std::string str)
{
    double d = std::stod(str);
    
    char c = static_cast<char>(d);
    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    int i = static_cast<int>(d);
    std::cout << "int: " << i << std::endl;

    float f = static_cast<float>(d);
    std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}

void    convertInff(std::string str)
{
    if (str == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void    convertInf(std::string str)
{
    if (str == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void    convertNanf()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void    convertNan()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void    ScalarConverter::convert(std::string str)
{
    std::string type = detectType(str);
    
    // std::cout << "type: " << type << std::endl;
    if (type == "int")
        convertInt(str);
    else if (type == "char")
        convertChar(str);
    else if (type == "float")
        convertFloat(str);
    else if (type == "double")
        convertDouble(str);
    else if (type == "inff")
        convertInff(str);
    else if (type == "inf")
        convertInf(str);
    else if (type == "nanf")
        convertNanf();
    else if (type == "nan")
        convertNan();
    else
        std::cout << "Error: The input \"" << str << "\" is not a valid scalar type." << std::endl;

}
