/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:23:55 by snegi             #+#    #+#             */
/*   Updated: 2024/06/26 13:23:57 by snegi            ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t result = std::time(NULL);
    std::tm* now = std::localtime(&result);
    
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", now);
    
    std::cout << buffer << std::flush;
}

Account::Account(int initial_deposit)
{
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
}

Account::~Account(void)
{
    _nbAccounts--;
    this->_displayTimestamp();
    std::cout <<"index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";" << "total:"
                << getTotalAmount() << ";" << "deposits:" << getNbDeposits()
                << ";" << "withdrawals:" << getNbWithdrawals() << std ::endl;
}

void Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "deposit:" << deposit << ";" << "p_amount:" << _amount << ";"
                << std::flush;
    _amount += deposit;
    std::cout << "deposit:" << deposit << ";" << "amount:" <<_amount << ";"
                <<"nb_deposit:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();
    std::cout << "index:" <<_accountIndex << ";" << "p_amount:" << _amount << ";"
                << "withdrawal:" << std::flush;
    if (withdrawal > checkAmount()){
        std::cout << "refused" << std::endl;
        return false;
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -=withdrawal;
    std::cout << withdrawal << ";" << "amount:" << _amount << ";" 
                << "nb_withdrawal:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void)const
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount
                << ";" << "deposits:" << _nbDeposits << ";" << "withdrawals:"
                << _nbWithdrawals << std::endl;
}