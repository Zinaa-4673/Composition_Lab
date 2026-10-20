 #include <iostream>
 #include <vector>
 #include <memory>
 #include "BankAccount.h"
 #include "CheckingAccount.h"
 #include "SavingAccount.h"

 int main() {
    std::vector<std::unique_ptr<BankAccount>> accounts;
        accounts.push_back(std::make_unique<CheckingAccount> ("CHK001", 500.0, 1.50));
        accounts.push_back(std::make_unique<SavingAccount> ("SAV001", 1200.0, 2.5));
        int choice;
        do{
            std::cout << "Bank Account Management System" << std::endl;
            std::cout << "1. Display Accounts" << std::endl;
            std::cout << "2. Deposit" << std::endl;
            std::cout << "3. Withdraw" << std::endl;
            std::cout << "4. Calculate Interest" << std::endl;
            std::cout << "5. add Account" << std::endl;
            std::cout << "6. add saving" << std::endl;
            std::cout << "0. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (choice == 1) {
                std::cout << "__All Accounts__" << std::endl;
                for (size_t i = 0; i < accounts.size(); ++i) {
                    std::cout << " [" << i << "]: ";
                    accounts[i]->display();
                }
            }
            else if (choice == 2) {
                size_t index;
                double amount;
                std::cout << " Enter deposit amount:";
                std::cin >> amount;
                if (index < accounts.size()) {
                    accounts[index]->deposit(amount);
                }else {
                    std::cout <<"Invalid index \n";
                }
            }
            else if (choice ==3) {
                size_t index;
                double amount;
                std::cout << "Enter account index:";
                std:: cin >> amount;
                if (index < accounts.size()) {
                    std::cout << "Enter withdrawal amount:";
                    std::cin >> amount;
                    accounts[index]-> withdraw(amount);
                } else {
                  std::cout << " Invalid index\n";
                }
            }
            else if (choice == 4) {
               size_t index;
               std::cout << " Enter saving account: ";
               std::cin >> index;
               if (index < accounts.size()) {
                SavingAccount* sav = dynamic_cast<SavingAccount*>(accounts[index].get());
                if (sav != nullptr) {
                    sav->calculateInterest();
                } else {
                    std::cout << "Error: the selected account is not saving\n";
                 }
               }
               else {
                std::cout << " Invild index\n";
               }
            }
             else if (choice ==5) {
               std:: string accnum;
               double balance, fee;
               std::cout << " Enter account number:";
               std::cin >> accnum;
               std::cout << " Enter blance:";
               std::cin >> balance;
               std::cout << " Enter Fee:";
               std::cin >> fee;
               accounts.push_back(std::make_unique<CheckingAccount>(accnum, balance, fee));
               std::cout << " Checking Account add successfully\n";
            }
             else if (choice == 6) {
               std:: string accnum;
               double balance, rate;
               std::cout << " Enter account number:";
               std::cin >> accnum;
               std::cout << " Enter blance:";
               std::cin >> balance;
               std::cout << " Enter Fee:";
               std::cin >> rate;
               accounts.push_back(std::make_unique<SavingAccount>(accnum, balance, rate));
               std::cout << " Saving Account add successfully\n";
             }
        } while (choice != 0);
        std::cout << "Exiting porgrame.\n";
        return 0;

        CheckingAccount checking ("CHK-101", 500.0, 1.50);
        checking.deposit(250.0);
        checking.withdraw(100.0);
        checking.withdraw(50.0);

        checking.printHistory();


        SavingAccount savings ("SAV-202",10000.0, 0.03);
         savings.deposit(500.0);
         savings.withdraw (200.0);

        savings.printHistory();

 }
