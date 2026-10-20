 #ifndef CHECKINGACCOUNT_H
 #define CHECKINGACCOUNT_H
 #include "BankAccount.h"

 class CheckingAccount : public BankAccount {
 private:
     double transactionFee;

 public:
     CheckingAccount(std::string accnum,double initialBalance, double transactionFee);
     bool withdraw(double amount)override;
     void display() const override;
 };
 #endif // CHECKINGACCOUNT_H
