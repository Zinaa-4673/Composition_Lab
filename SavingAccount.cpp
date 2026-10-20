#include "SavingAccount.h"
#include <iostream>

SavingAccount::SavingAccount(std::string accnum, double Balance, double Rate)
    : BankAccount(accnum, Balance), interestRate(interestRate) {}

void SavingAccount::addInterest() {
    double interest = balance * (interestRate / 100);
    balance += interest;
    std::cout << "Interest calculated: $" << interest << ".new balance: $" << balance << std::endl;
    deposit(interest);

}

void SavingAccount::display() const {
    std::cout << "[Saving Account]" << std::endl;
    BankAccount::display();
    std::cout << "Interest Rate: " << interestRate << std::endl;
}