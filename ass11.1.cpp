#include <iostream>
#include <string>
// Base  Class
class PaymentMethod {
 private:
  double amount = 0.0;

 public:
  PaymentMethod(double amount) { this->amount = amount; }
  void Set_Amount(double amount) { this->amount = amount; }
  double Get_Amount(void) { return this->amount; };
};
class CreditCard : public PaymentMethod {
 private:
  int card_number = 0;

 public:
  CreditCard(double amount, int card_number) : PaymentMethod(amount) {
    this->card_number = card_number;
  }
  void processPayment() {
    std::cout << "Card Number is: " << this->card_number << std::endl;
    std::cout << "Amount is: " << Get_Amount() << std::endl;
  }
};
class PayPal : public PaymentMethod {
 private:
  std::string Email;

 public:
  PayPal(double amount, std::string Email) : PaymentMethod(amount) {
    this->Email = Email;
  }
  void processPayment() {
    std::cout << "User Email is: " << this->Email << std::endl;
    std::cout << "Amount is: " << Get_Amount() << std::endl;
  }
};
int main() {
  CreditCard ali(100, 122435);
  PayPal hady(100000, "hadyayman899@gmail.com");

  ali.processPayment();
  hady.processPayment();

  return 0;
}