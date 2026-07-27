/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:47:57 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/27 19:57:39 by admin            ###   ########.fr       */
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

int Account::getNbAccounts( void ) { return _nbAccounts; }
int Account::getTotalAmount( void ) { return _totalAmount; }
int Account::getNbDeposits( void ) { return _totalNbDeposits; }
int Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

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

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();

	std::cout << " accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;	
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();

	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;		
}

void Account::makeDeposit( int deposit)
{
	_displayTimestamp();
	
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;

	_amount+=deposit;
	_nbDeposits++;

	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;

	_totalAmount+=deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();

	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;

	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused\n";
		return false;	
	}
	_amount-=withdrawal;
	_nbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

	_totalAmount-=withdrawal;
	_totalNbWithdrawals++;

	return true;
}

int Account::checkAmount( void ) const { return _amount;}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_nbAccounts++;

	_displayTimestamp();

	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created\n";
}

Account::~Account( void )
{
	_displayTimestamp();

	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed\n";

	_nbAccounts--;
}