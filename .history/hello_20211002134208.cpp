#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> brothers{"David", "Alan", "Roman"};
  for (std::string const&brother : brothers) {
    std::cout << "Hello" << brother << "!\n";
  }

  std::cout << "Hello world!\n" << std::endl;
}