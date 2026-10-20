 #ifndef SAVINGACCOUNT_H
 #define SAVINGACOOUNT_H
 #include "BankAccount.h"

 class SavingAccount : public BankAccount {
    private:
        double interestRate;

    public: 
        SavingAccount(std::string accnum, double balance, double rate);
        void calculateInterest();
        void display() const override;
        void addInterest();
 };

 #endif