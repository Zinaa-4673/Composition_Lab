 #ifndef TRANSACTION_H
 #define TRANSACTION_H

 #include <string>

class Transaction {
public:
   std::string type;
   double amount;
   std::string timestamp;

   Transaction(std::string t, double amt, std::string time) {
    type = t;
    amount = amt;
    timestamp = time;

   }
   

 };

 #endif
 