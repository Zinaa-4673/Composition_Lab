#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <vector>
#include "Transaction.h"

class BankAccount {
protected:
    std::string accountNumber;
    double balance;
    std::vector<Transaction> transactionHistory;


public:
    BankAccount(std::string accnum, double initialBalance);

    virtual ~BankAccount();
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual void display() const;

    double getBalance() const;
    std::string getAccountNumber() const;
    void printHistory();
};

#endif // BankAccount_H