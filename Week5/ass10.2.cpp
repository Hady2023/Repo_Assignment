#include <iostream>
#include <string>
#include <vector>

struct Item {
  std::string name;
  float Price;
  int Quantity;
};
int main() {
  int n1;
  std::string Input_item, Item_search;
  int Item_price, new_price;
  int Item_Quantity;
  std::cout << "Inter Index of the inventory list " << std::endl;
  std::cin >> n1;
  std::vector<Item> List_item(n1);
  for (int i = 0; i < List_item.size(); i++) {
    std::cout << "Item: " << i + 1 << std::endl;
    std::cout << "Item Name:  " << std::endl;
    std::cin >> Input_item;
    List_item[i].name = Input_item;
    std::cout << "Item Price: " << std::endl;
    std::cin >> Item_price;
    List_item[i].Price = Item_price;
    std::cout << "Item Quantity: " << std::endl;
    std::cin >> Item_Quantity;
    List_item[i].Quantity = Item_Quantity;
    std::cout << "**********" << std::endl;
  }
  auto lamp_update_price = [&List_item](std::string name,
                                        int new_price) -> void {
    for (int i = 0; i < List_item.size(); i++) {
      if (List_item[i].name == name) {
        List_item[i].Price = new_price;
      } else {
        std::cout << "Item not Found " << std::endl;
      }
    }
  };
  std::cout << "Enter Item Name and New_price to up date the Item : "
            << std::endl;
  std::cout << "Item_Up_Date: " << std::endl;
  std::cin >> Item_search;
  std::cout << "New_Price: " << std::endl;
  std::cin >> new_price;
  lamp_update_price(Item_search, new_price);
  auto OutOfStock = [List_item](std::string name) -> bool {
    for (int i = 0; i < List_item.size(); i++) {
      if (List_item[i].name == name && List_item[i].Quantity > 0) {
        return true;
      }
    }
    return false;
  };
  std::cout << "Enter Name for Item to serche on stock: " << std::endl;
  std::cin >> Item_search;
  if (OutOfStock(Item_search))
    std::cout << "Found Item in stock " << std::endl;
  else
    std::cout << "Item Not Found" << std::endl;
  auto Calc_Total = [&List_item]() -> double {
    double res = 0;
    for (int i = 0; i < List_item.size(); i++) {
      res = res + (List_item[i].Price * List_item[i].Quantity);
    }
    return res;
  };
  std::cout << "Total Amount of Inventory is: " << Calc_Total() << std::endl;
  return 0;
}
