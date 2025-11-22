/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 02:20:07 by nhendrik          #+#    #+#             */
/*   Updated: 2025/11/22 02:55:15 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <chrono>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	//[19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	_amount = initial_deposit;

	_accountIndex = _nbAccounts;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
	_nbWithdrawals = 0;
}

Account::~Account(void) {
	 std::cout << "Destructor Called" << std::endl;
}


void	Account::makeDeposit(int deposit) {
	_nbDeposits++;
	//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposists:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

void	Account::_displayTimestamp(void) {
	
}


int		Account::checkAmount( void ) const {
	return (0);
}
void	Account::displayStatus( void ) const {
	
}

void	Account::displayAccountsInfos( void ) {
	
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (_amount - withdrawal < 0)
		return (false);
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	return (true);
}

int Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

