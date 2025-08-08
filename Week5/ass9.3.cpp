#include <iostream>
int main() {
  int x = 3;
  int y = 9;
  int z = 10;

  auto Func_ref_1 = [&x, &y, &z]() -> void {
    std::cout << "x: " << x * 2 << "\n";
    std::cout << "y: " << y * 2 << "\n";
    std::cout << "z: " << z * 2 << "\n";
  };
  auto Func_val_2 = [x, y, z]() -> void {
    std::cout << "x: " << x << "\n";
    std::cout << "y: " << y << "\n";
    std::cout << "z: " << z << "\n";
  };
  auto Func_val_3_inc = [&x, &y](int num) -> void {
    std::cout << "x: " << x + num << "\n";
    std::cout << "y: " << y + num << "\n";
  };
  Func_ref_1();
  Func_val_2();
  Func_val_3_inc(10);
  return 0;
}