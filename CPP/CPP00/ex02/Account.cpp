/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:30:20 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/04 11:23:56 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbDeposits = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex \
	<< ";amount:" << checkAmount() \
	<< ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex \
	<< ";amount:" << checkAmount() \
	<< ";closed" << std::endl;
	Account::_nbAccounts--;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() \
	<< ";total:" << Account::getTotalAmount() \
	<< ";deposits:" << Account::getNbDeposits() \
	<< ";withdrawals:" << Account::getNbWithdrawals() \
	<< std::endl;

}

void	Account::_displayTimestamp(void)
{
	time_t	current_time;

	current_time = time(NULL);
	std::cout << std::put_time(localtime(&current_time), "[%Y%m%d_%H%M%S] ");
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex \
	<< ";p_amount:" << checkAmount() - deposit \
	<< ";deposit:" << deposit \
	<< ";amount:" << checkAmount() \
	<< ";nb:deposits:" <<  _nbDeposits \
	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";p_amount:" << checkAmount();

	if (checkAmount() < withdrawal)
	{
		std::cout << ";refused" << std::endl;
		return (0);
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	
	std::cout << ";withdrawal:" << withdrawal \
	<< ";amount:" << checkAmount() \
	<< ";nb_withdrawals:" << _nbWithdrawals \
	<< std::endl;

	return (0);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex \
	<< ";amount:" << checkAmount() \
	<< ";deposits:" << _nbDeposits \
	<< ";withdrawals:" << _nbWithdrawals \
	<< std::endl;
}
