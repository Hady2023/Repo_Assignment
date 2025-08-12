#include <iostream>
#include <string>
#include <vector>
class LibraryItem {
 public:
  virtual void displayInfo() const = 0;
  virtual bool isAvailable() const = 0;
  virtual void borrowItem() = 0;
  virtual void returnItem() = 0;
};
class Book : public LibraryItem {
 private:
  std::string title;
  std::string author;
  bool available;

 public:
  Book(const std::string& t, const std::string& a)
      : title(t), author(a), available(true) {}
  void displayInfo() const override {
    std::cout << "=====Book====\n"
              << "title: " << this->title << "\nauthor: " << this->author
              << "\nStatus: " << (available ? "Available " : " Borrowed")
              << "\n-----------------------\n";
  }
  bool isAvailable() const override { return available; }
  void borrowItem() override {
    if (isAvailable()) {
      std::cout << "You Borrowed Book: " << this->title << std::endl;
      available = false;
    } else {
      std::cout << " Book  is already Borrowed  : " << title << std::endl;
    }
  }
  void returnItem() override {
    available = true;
    std::cout << "Book is Return and its Avilable" << std::endl;
  }
};
class Magazine : public LibraryItem {
 private:
  std::string title;
  int issueNumber;
  bool available;

 public:
  Magazine(const std::string& t, const int& mnum)
      : title(t), issueNumber(mnum), available(true) {}

  void displayInfo() const override {
    std::cout << "=====Magazine======\n"
              << "\nTitle: " << title << "\nMagazine Number" << issueNumber
              << "\nStatus: " << (available ? "Available" : "Borrowed")
              << "\n------------------------\n";
  }
  bool isAvailable() const override { return this->available; }
  void borrowItem() override {
    if (isAvailable()) {
      available = false;
      std::cout << "You Borrowed Magazine: " << title << std::endl;
    } else {
      std::cout << " Magazine  is already Borrowed  : " << std::endl;
    }
  }
  void returnItem() override {
    available = true;
    std::cout << "Magazine is Return and its Avilable" << std::endl;
  }
};

int main() {
  std::vector<LibraryItem*> Item;

  Item.push_back(new Book("The Great Gatsby", "F. Scott Fitzgerald"));
  Item.push_back(new Book("1984", "George Orwell"));
  Item.push_back(new Magazine("National Geographic", 202));
  Item.push_back(new Magazine("TIME", 58));
  for (auto Elemnt : Item) {
    Elemnt->displayInfo();
  }
  Item[0]->borrowItem();
  Item[0]->returnItem();
  return 0;
}