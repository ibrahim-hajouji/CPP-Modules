/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:35:48 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/27 19:57:35 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
    {
        _nbrs = src._nbrs;
    }
    return *this;
}

RPN::~RPN()
{
}

int RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::isSpace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}

double RPN::getResult() const
{
    return _result;
}

void RPN::validateInput(std::string input)
{
    int numberCount = 0;
    bool operatorExist = false;
    
    if (input.empty() || std::all_of(input.begin(), input.end(), RPN::isSpace))
        throw (std::runtime_error("Invalid input: Empty input"));
    for (std::string::size_type i = 0; i < input.size(); i++)
    {
        if (isSpace(input[i]))
            continue;
        
        if (isdigit(input[i]))
        {
            if (i < input.size() - 1 && isdigit(input[i + 1]))
                throw (std::runtime_error("Invalid input: Number should be from 0-9"));
            numberCount++;
        }
        else if (isOperator(input[i]))
        {
            operatorExist = true;
            if (numberCount < 2)
                throw(std::runtime_error("Invalid input: Insufficient number of operands"));
            numberCount--;
        }
        else
            throw (std::runtime_error("Invalid input: Only numbers and operators are allowed"));
    }
    
    if (numberCount != 1)
        throw (std::runtime_error("Invalid input: Too many numbers or insufficient operators"));
    
    if (!operatorExist)
        throw (std::runtime_error("Invalid input: No operator found"));
}

void    RPN::calculate(std::string input)
{
    for (std::string::size_type i = 0; i < input.size(); i++)
    {
        if (isSpace(input[i]))
            continue;

        if (isdigit(input[i]))
            _nbrs.push(input[i] - '0');
        
        else if (isOperator(input[i]))
        {
            if (_nbrs.size() < 2)
                throw (std::runtime_error("Invalid input: Insufficient number of operands"));
            double a = _nbrs.top();
            _nbrs.pop();
            double b = _nbrs.top();
            _nbrs.pop();
            
            switch (input[i])
            {
                case '+':
                    _nbrs.push(a + b);
                    break;

                case '-':
                    _nbrs.push(b - a);
                    break;

                case '*':
                    _nbrs.push(a * b);
                    break;

                case '/':
                    if (a == 0)
                        throw (std::runtime_error("Invalid input: Division by zero"));
                    _nbrs.push(b / a);
                    break;
            }
        }
        else
            throw (std::runtime_error("Invalid input: Only numbers and operators are allowed"));
    }
    if (_nbrs.size() != 1)
        throw (std::runtime_error("Invalid input: Too many numbers or insufficient operators"));
    _result = _nbrs.top();
    _nbrs.pop();
}
