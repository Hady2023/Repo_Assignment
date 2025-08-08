#include <functional>
#include <iostream>
int main() {
  int x = 3;
  int y = 9;
  int z = 10;
  auto Mult_cap = [&x, &y, &z]() -> void {
    std::cout << "x after Multiply: " << x * 2 << std::endl;
    std::cout << "y after Multiply: " << y * 2 << std::endl;
    std::cout << "z after Multiply: " << z * 2 << std::endl;
  };
  auto Mult_copy = [x, y, z]() -> void {
    std::cout << "copy_X: " << "\t" << x << "\t" << "Copy_Y: " << y << "\t"
              << "Copy_Z: " << z << std::endl;
  };
  auto Capt_Spec = [&x, &y](int num_fac) -> void {
    x += num_fac;
    y += num_fac;
    std::cout << "Prints the updated values of x and y: " << x << " " << y
              << std::endl;
  };
  // calls
  Mult_cap();
  Mult_copy();
  Capt_Spec(10);
  return 0;
}