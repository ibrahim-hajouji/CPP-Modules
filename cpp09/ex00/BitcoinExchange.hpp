/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:17:26 by ihajouji          #+#    #+#             */
/*   Updated: 2025/01/23 11:54:31 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <algorithm>

class BitcoinExchange
{

	private:
		std::map<std::string, float> _database;
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &src);
		
		const std::map<std::string, float> &getDatabase() const;

		void	loadDatabase(const std::string &filename);
		void	processInputFile(const std::string &filename) const;
		bool	valid_date(const std::string &date) const;
		bool	valid_value(const std::string &value) const;
		float	walletValue(const std::string &date, const std::string &value) const;
};

#endif