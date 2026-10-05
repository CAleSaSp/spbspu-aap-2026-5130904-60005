#include <cstddef>
#include <iostream>

int main()
{
  long long prev = 0, curr = 0;
  std::size_t count = 0, length = 0;

  while (true) {
    std::cin >> curr;

    if (std::cin.bad() || std::cin.fail()) {
      std::cerr << "Invalid argument\n";
      return 1;
    }

    if (curr == 0) {
      break;
    }

    if (length > 0 && curr % prev == 0) {
      ++count;
    }

    prev = curr;
    ++length;
  }

  if (length < 2) {
    std::cerr << "Too short\n";
    return 2;
  }

  std::cout << count << std::endl;
}
