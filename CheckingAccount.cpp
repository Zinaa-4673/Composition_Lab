 #include "CheckingAccount.h"
 #include <iostream>

    CheckingAccount::CheckingAccount(std::string accnum,double initialBalance, double transactionFee)
    : BankAccount(accnum, initialBalance), transactionFee(transactionFee)
    {
    }

    bool CheckingAccount::withdraw(double amount) {
        double totalAmount = amount + transactionFee;
        if (totalAmount > 0 && totalAmount <= balance) {
            balance -= totalAmount;

            std::cout << "Withdrawal: $"  << amount << "Fee: $" << transactionFee << ".New Balance: $ " << balance << std::endl;
        } else {
            std::cout << "Invalid Withdrawal Amount or Insufficient Funds." << std::endl;
        }
    }

    void CheckingAccount::display() const {
        std::cout << "[Checking Account]" << std::endl;
        BankAccount::display();
        std::cout << "Transaction Fee: $" << transactionFee << std::endl;
       
    }