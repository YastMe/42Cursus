/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:15:03 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/21 16:15:04 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <string>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define DEFAULT "\033[0m"

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
		void							_parseData(const std::string &filename);
		bool							_checkValidDate(const std::string &date) const;
		bool							_dateExist(const std::string &date) const;
		void							_getLastValidDate(std::string &date, float value) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bitcoinexchange);
		~BitcoinExchange();
		BitcoinExchange & operator = (const BitcoinExchange &bitcoinexchange);
		void							processFile(const std::string &filename);
		std::map<std::string, float>	getData() const;
};

std::ostream & operator << (std::ostream &out, const BitcoinExchange &bitcoinexchange);

#endif