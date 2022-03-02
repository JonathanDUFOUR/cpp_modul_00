/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 02:13:27 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 17:47:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iomanip>
#include <iostream>
#include "class/Account.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Account::Account(int initialDeposit) :
	_accountIndex(Account::_nbAccounts++),
	_amount(initialDeposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_totalAmount += initialDeposit;
	Account::_displayTimestamp();
	std::cout << " "
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "created" << std::endl;
}

Account::Account(void) :
	_accountIndex(Account::_nbAccounts++),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << " "
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "created" << std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Account::~Account(void)
{
	--Account::_nbAccounts;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	Account::_displayTimestamp();
	std::cout << " "
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "closed" << std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

// ************************************************************************** //
//                          Private Member Functions                          //
// ************************************************************************** //

void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		*timeinfo;

	std::time(&now);
	timeinfo = std::localtime(&now);
	std::cout << "["
	<< std::setfill('0')
	<< std::setw(4) << timeinfo->tm_year + 1900
	<< std::setw(2) << timeinfo->tm_mon + 1
	<< std::setw(2) << timeinfo->tm_mday
	<< "_"
	<< std::setw(2) << timeinfo->tm_hour
	<< std::setw(2) << timeinfo->tm_min
	<< std::setw(2) << timeinfo->tm_sec
	<< std::setw(1)
	<< "]";
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	Account::makeDeposit(int deposit)
{
	int const	p_amount = this->_amount;

	this->_amount += deposit;
	++this->_nbDeposits;
	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
	Account::_displayTimestamp();
	std::cout << " "
	<< "index:" << this->_accountIndex << ";"
	<< "p_amount:" << p_amount << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " "
	<< "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";"
	<< "withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	++this->_nbWithdrawals;
	Account::_totalAmount -= withdrawal;
	++Account::_totalNbWithdrawals;
	std::cout << withdrawal << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " "
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " "
	<< "accounts:" << Account::_nbAccounts << ";"
	<< "total:" << Account::_totalAmount << ";"
	<< "deposits:" << Account::_totalNbDeposits << ";"
	<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

// ************************************************************************** //
//                             Private Attributes                             //
// ************************************************************************** //
int	Account::_nbAccounts(0);
int	Account::_totalAmount(0);
int	Account::_totalNbDeposits(0);
int	Account::_totalNbWithdrawals(0);
