/*Using Ai to Add comment only*/
#include <algorithm>   // For std::sort
#include <functional>  // For std::function
#include <iostream>    // For input/output
#include <vector>      // For std::vector
#define ascending <    // Macro to make "a ascending b" equivalent to "a < b"

// Function that accepts two callable references (swap and print)
// Both must be std::function<bool(void)>, meaning: take no parameters, return
// bool
void Calculate(std::function<bool(void)> &swap,
               std::function<bool(void)> &print) {
  swap();   // Call the swap lambda
  print();  // Call the print lambda
}

int main() {
  int n1, n2;  // Sizes for the two vectors

  // Declare two std::function variables for later assignment
  std::function<bool(void)> swap;
  std::function<bool(void)> print;

  // Ask user for vector sizes
  std::cout << "Enter Size of Vector 1 : " << std::endl;
  std::cin >> n1;
  std::vector<int> nums_v1(n1);  // Create vector 1 with size n1

  std::cout << "Enter Size of Vector 2 : " << std::endl;
  std::cin >> n2;
  std::vector<int> nums_v2(n2);  // Create vector 2 with size n2

  // Input for vector 1
  std::cout << "Enter Vector 1 " << std::endl;
  for (auto it = nums_v1.begin(); it != nums_v1.end(); ++it) {
    std::cin >>
        *it;  // Store input directly into the element pointed by iterator
  }

  // Input for vector 2
  std::cout << "Enter Vector 2" << std::endl;
  for (auto it = nums_v2.begin(); it != nums_v2.end(); ++it) {
    std::cin >> *it;
  }

  // Lambda to sort vector 2 and swap its elements with vector 1
  swap = [&nums_v1, &nums_v2]() -> bool {
    // Sort vector 2 in ascending order using a custom comparator
    std::sort(nums_v2.begin(), nums_v2.end(),
              [](int a, int b) -> bool { return a ascending b; });

    // Swap elements between vector 1 and vector 2 (element-wise)
    if (nums_v1.size() == nums_v2.size()) {
      for (int i = 0; i < nums_v2.size(); i++) {
        int temp = nums_v1[i];
        nums_v1[i] = nums_v2[i];
        nums_v2[i] = temp;
      }
    } else if (nums_v1.size() > nums_v2.size()) {
      for (int i = 0; i < nums_v2.size(); i++) {
        int temp = nums_v1[i];
        nums_v1[i] = nums_v2[i];
        nums_v2[i] = temp;
      }
    } else {
      for (int i = 0; i < nums_v1.size(); i++) {
        int temp = nums_v2[i];
        nums_v2[i] = nums_v1[i];
        nums_v1[i] = temp;
      }
    }
    return true;  // Indicate success
  };

  // Lambda to print the contents of both vectors after swapping
  print = [&nums_v1, &nums_v2]() -> bool {
    // Show which elements were swapped
    for (int i = 0; i < nums_v1.size(); i++) {
      std::cout << " Element swaped from V2(sorted) to V1 : " << nums_v1[i]
                << std::endl;
    }

    // Print contents of vector 1
    std::cout << "Vector1 conntent After Swaping: " << std::endl;
    for (int i = 0; i < nums_v1.size(); i++) {
      std::cout << nums_v1[i] << std::endl;
    }

    // Print contents of vector 2
    std::cout << "Vector2 conntent after Swaping: " << std::endl;
    for (int i = 0; i < nums_v2.size(); i++) {
      std::cout << nums_v2[i] << std::endl;
    }

    // Explanation message
    std::cout << "v1 now holds the sorted elements from v2, and v2 holds the "
                 "original elements from v1"
              << std::endl;
    return true;  // Indicate success
  };

  // Call the Calculate function, passing our two lambdas
  Calculate(swap, print);

  return 0;  // End of program
}
