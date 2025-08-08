#include <iostream>
#include <string>
class Student {
 private:
  std::string Name;
  int ID;
  int Age;

 public:
  Student(std::string Name, int ID, int Age) {
    this->Name = Name;
    this->ID = ID;
    this->Age = Age;
  }
  void Set_ID(int ID) { this->ID = ID; }
  void Set_Age(int Age) { this->Age = Age; }
  void Set_name(std::string name) { this->Name = name; }
  void Get_ID() { std::cout << "ID: " << this->ID << std::endl; }
  void Get_Age() { std::cout << "Age: " << this->Age << std::endl; }
  void Get_name() { std::cout << "Name: " << this->Name << std::endl; }
};
int main() {
  Student s1("hady", 123, 25);
  Student s2("ali", 456, 20);
  Student s3("Ahmed", 500, 30);
  s1.Set_Age(26);
  s1.Get_Age();
  s1.Get_name();

  return 0;
}