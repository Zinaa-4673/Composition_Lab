 #include "BankAccount.h"
 #include <iostream>
 #include <ctime>
 #include <iomanip>
 #include <sstream>

std::string getCurrentTimestamp() {
   std::time_t now = std::time(nullptr);
   std::tm* localtime = std::localtime(&now);

   std::ostringstream output;
   output << std::put_time(localtime, "%Y-%m-%d %H:%M:%S");
   return output.str();
}
 BankAccount::BankAccount(std::string accnum, double initialBalance)
        : accountNumber(accnum), balance(initialBalance) {}

 BankAccount::~BankAccount() {}
 
 void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cerr << "invalid deposit amount.\n";
        return;
    }

    balance += amount;
    transactionHistory.push_back({
      "deposit", amount , getCurrentTimestamp()});

   std::cout << "deposited: $" << amount << ".new balance: $" << balance << '\n';
 }
 
 bool bankAccount::withdraw (double amount) {
   if (amount <= 0 && amount > balance) {
      std::cerr << " Invalid withdeawal amoutn. \n";
      return false;
   };
   balance -= amount;
   transactionHisory.push_back({
      "withdrawal", amount, getCurrentTimestamp() });

   std::cout << "withdrawal: $" << balance <<'\n';
   return true;
 }

 void BankAccount::display() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
 }

 double BankAccount::getBalance() const {
    return balance;
 }

 std::string BankAccount::getAccountNumber() const {
    return accountNumber;
 }

 void BankAccount::printHistory() {
   std::cout << "\nTransaction Hisory for account:" << accountNumber << "\n";

   if(transactionHistory.empty()) {
      std::cout << "no transcations yet.\n";
      return;

   }

   for (const Transaction& transaction: transactionHistory) {
      std::cout <<"type:" << transaction.type << " amount: $" << transaction.amount << "time:" << transaction.timestamp << "\n";

   }
   
 }