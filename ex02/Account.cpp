/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:47:57 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/24 16:12:15 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

void Account::_displayTimestamp( void )
{
	std::time_t time;
	std::time(&time);

	struct tm* htime;
	htime = std::localtime(&time);

	std::cout << std::setfill('0');
	std::cout << "[" << htime->tm_year + 1900;
	std::cout << std::setw(2) << htime->tm_mon + 1;
	std::cout << std::setw(2) << htime->tm_mday << "_";
	std::cout << std::setw(2) << htime->tm_hour;
	std::cout << std::setw(2) << htime->tm_min;
	std::cout << std::setw(2) << htime->tm_sec << "]";
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;

	_displayTimestamp();

	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created\n";
}