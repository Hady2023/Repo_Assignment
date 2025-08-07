#include <algorithm>
#include <iostream>
#include <vector>
bool Test_vec(std::vector<int>& true_nums) {
  int i = 0;
  std::sort(true_nums.begin(), true_nums.end());
  while (true_nums[i] < true_nums[i + 1]) {
    int val = true_nums[i + 1] - true_nums[i];
    true_nums[i + 1] = (true_nums[i + 1] - val) + 1;
    std::cout << "sorted element: " << true_nums[i] << std::endl;
    i++;
  }
  std::cout << "end element: " << *(true_nums.end() - 1) << std::endl;
  return true;
}
int main() {
  int size;
  std::cout << "Enter size of the vector" << std::endl;
  std::cin >> size;
  std::vector<int> nums(size);
  std::cout << "Enter element of vector" << std::endl;
  for (int i = 0; i < nums.size(); i++) {
    std::cin >> nums[i];
  }
  if (Test_vec(nums)) std::cout << "all element is sorted" << std::endl;

  return 0;
}