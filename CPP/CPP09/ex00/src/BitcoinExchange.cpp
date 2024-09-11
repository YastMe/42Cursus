/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:14:58 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/21 16:28:59 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

/**
 * Base methods.
 * 
 */

BitcoinExchange::BitcoinExchange(){_parseData("data.csv");}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinexchange){*this = bitcoinexchange;}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange &bitcoinexchange)
{
	if (this != &bitcoinexchange)
		_data = bitcoinexchange.getData();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &bitcoinexchange)
{
	const std::map<std::string, float>	data = bitcoinexchange.getData();
	for (std::map<std::string, float>::const_iterator it = data.begin(); it != data.end(); it++)
		out << it->first << " " << it->second << std::endl;
	return (out);
}

/**
 * Private methods.
 * 
 */

bool	BitcoinExchange::_checkValidDate(const std::string &date) const
{
	int	year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());

	if (date.size() != 10)
		return (false);
	else if (date[4] != '-' || date[7] != '-')
		return (false);
	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2 && day > 28 && year % 4 != 0)
		return (false);
	if (month == 2 && day > 29 && year % 4 == 0)
		return (false);
	return (true);
}

static void	previousDate(int *year, int *month, int *day)
{
	if (*day == 1)
	{
		if (*month == 1)
		{
			*year -= 1;
			*month = 12;
		}
		else
			*month -= 1;
		if (*month == 4 || *month == 6 || *month == 9 || *month == 11)
			*day = 30;
		else if (*month == 2)
		{
			if (*year % 4 == 0)
				*day = 29;
			else
				*day = 28;
		}
		else
			*day = 31;
	}
	else
		*day -= 1;
}

bool	BitcoinExchange::_dateExist(const std::string &date) const
{
	// std::cout << YELLOW << "Checking date: " << date << DEFAULT << std::endl;
	if (_data.find(date) != _data.end())
		return (true);
	return (false);
}	

void	BitcoinExchange::_getLastValidDate(std::string &date, float value) const
{
	int			year = atoi(date.substr(0, 4).c_str());
	int			month = atoi(date.substr(5, 2).c_str());
	int			day = atoi(date.substr(8, 2).c_str());
	std::string	new_date = date;

	while (!_dateExist(new_date) && year >= 2009)
	{
		previousDate(&year, &month, &day);
		std::stringstream	ss;
		if (month < 10)
			ss << year << "-0" << month << "-";
		else
			ss << year << "-" << month << "-";
		if (day < 10)
			ss << "0" << day;
		else
			ss << day;
		new_date = ss.str();
	}
	if (_dateExist(new_date))
		std::cout << GREEN << date << " => " << value << " = " << value * this->_data.find(new_date)->second << DEFAULT << std::endl;
	else
		std::cerr << RED << "Error: no data found for this date: " << date << DEFAULT << std::endl;
}

void	BitcoinExchange::_parseData(const std::string &filename)
{
	std::ifstream	stream;
	std::string		line;
	std::string		key_date;
	float			value;

	stream.open(filename.c_str());
	if (!stream.is_open())
	{
		std::cerr << "Error: Couldn't open " << filename << std::endl;
		return ;
	}
	while (std::getline(stream, line))
	{
		key_date = line.substr(0, line.find(','));
		value = atof(line.substr(line.find(",") + 1).c_str());
		_data.insert(std::pair<std::string, float>(key_date, value));
	}
	stream.close();
}

/**
 * Public methods.
 * 
 */

void	BitcoinExchange::processFile(const std::string &filename)
{
	std::ifstream	stream;
	std::string		line;
	std::string		key_date;
	float			value;

	stream.open(filename.c_str());
	if (!stream.is_open())
	{
		std::cerr << "Error: Couldn't open " << filename << std::endl;
		return ;
	}
	while (std::getline(stream, line))
	{
		if (line.empty() || line[0] == '#' || line == "date | value")
			continue ;
		key_date = line.substr(0, line.find(' '));
		value = atof(line.substr(line.find("|") + 1).c_str());
		if (line.find("|") == std::string::npos)
			std::cerr << RED << "Error: bad input => " << line << DEFAULT << std::endl;
		else if (value > 1000)
			std::cerr << RED << "Error: too large a number." << DEFAULT << std::endl;
		else if (value < 0)
			std::cerr << RED << "Error: not a positive number." << DEFAULT << std::endl;
		else if (!_checkValidDate(key_date))
			std::cerr << RED << "Error: bad date => " << line << DEFAULT << std::endl;
		else if (_dateExist(key_date))
			std::cerr << GREEN << key_date << " => " << value << " = " << _data[key_date] << DEFAULT << std::endl;
		else
			_getLastValidDate(key_date, value);
	}
	stream.close();
}

std::map<std::string, float>	BitcoinExchange::getData() const{return (_data);}
