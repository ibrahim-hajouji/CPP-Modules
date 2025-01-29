/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:22:57 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/27 13:49:22 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    _database = src._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

const std::map<std::string, float> &BitcoinExchange::getDatabase() const
{
    return _database;
}

void    BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream infile(filename);
    std::string buffer;
    
    if (infile.is_open() == 0)
        throw(std::runtime_error("DataBase file could not be opened"));

    while (std::getline(infile, buffer))
    {
        if (buffer == "date,exchange_rate")
            continue;
        std::string date = buffer.substr(0, 10);
        std::string value = buffer.substr(11);
        _database.insert(std::pair<std::string, float>(date, std::stof(value)));
}
    infile.close();
}

bool    BitcoinExchange::valid_date(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad date => " << date << std::endl;
        return 0;
    }
    
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    
    if (std::all_of(year.begin(), year.end(), ::isdigit) == 0 || std::all_of(month.begin(), month.end(), ::isdigit) == 0 || std::all_of(day.begin(), day.end(), ::isdigit) == 0)
    {
        std::cerr << "Error: bad date => " << date << std::endl;
        return 0;
    }
    
    int _year = std::stoi(year);
    int _month = std::stoi(month);
    int _day = std::stoi(day);
    
    if (_year < 2009 || _year > 2025 || _month < 1 || _month > 12)
    {
        std::cerr << "Error: bad date => " << date << std::endl;
        return 0;
    }
    
    int max_day = 31;
    if (_month == 2)
    {
        bool isLeapYear = (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
        max_day = isLeapYear ? 29 : 28;
    }
    else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
        max_day = 30;

    if (_day < 1 || _day > max_day)
    {
        std::cerr << "Error: bad date => " << date << std::endl;
        return 0;
    }
    return 1;
}

bool    BitcoinExchange::valid_value(const std::string &value) const
{
    if (value.empty())
    {
        std::cerr << "Error: bad value => " << value << std::endl;
        return 0;
    }
    
    if (value[0] == '-')
    {
        std::cerr << "Error: not a positive value." << std::endl;
        return 0;
    }

    int num_start = 0;
    while (value[num_start] == '+')
        num_start++;
    
    int has_dot = 0;
    if (num_start > 1 || (num_start == 1 && value.size() == 1))
    {
        std::cerr << "Error: bad value => " << value << std::endl;
        return 0;
    }
    for (size_t i = num_start; i < value.size(); i++)
    {
        if (has_dot > 1)
        {
            std::cerr << "Error: bad value => " << value << std::endl;
            return 0;
        }

        if (value[i] == '.')
        {
            has_dot++;
            if (i == value.size() - 1)
            {
                std::cerr << "Error: bad value => " << value << std::endl;
                return 0;
            }
        }
        
        if (std::isdigit(value[i]) == 0 && value[i] != '.')
        {
            std::cerr << "Error: bad value => " << value << std::endl;
            return 0;
        }
    }

    double valueD = std::stod(value);
    
    
    if (valueD > 1000)
    {
        std::cerr << "Error: too large number."<< std::endl;
        return 0;
    }
    
    return 1;
}

float  BitcoinExchange::walletValue(const std::string &date, const std::string &value) const
{
    float valueF = std::stof(value);

    std::map<std::string, float>::const_iterator it;

    it = _database.lower_bound(date);

    if (it == _database.end() || it->first != date)
    {
        if (it == _database.begin())
        {
            std::cerr << "Error: no earlier date found for " << date << std::endl;
            return 0;
        }
        it--;
    }

    return valueF * it->second;
    
}


void    BitcoinExchange::processInputFile(const std::string &filename) const
{
    std::ifstream infile(filename);
    if (!infile.is_open())
        throw std::runtime_error("Input file could not be opened");
    
    std::string buffer;
    for (int i = 0; getline(infile, buffer); i++)
    {
        if (i == 0)
        {
            if (buffer != "date | value")
                throw std::runtime_error("Input file must start with 'date | value'");
            continue;
        }
        
        size_t delimiterPos = buffer.find(" | ");
        if (delimiterPos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << buffer << std::endl;
            continue;
        }

        std::string date = buffer.substr(0, delimiterPos);
        std::string valueStr = buffer.substr(delimiterPos + 3);

        if (valid_date(date) == 0)
            continue;
            
        if (valid_value(valueStr) == 0)
            continue;
        
        float result = walletValue(date, valueStr);
        std::cout << date << " => " << valueStr << " = " << result << std::endl;

        
    }
}