#include <iostream>

int main()
{
  const int code_invalid_input = 1;
  const int code_too_short_seq = 2;
  const int min_length_of_seq = 2;

  long long prev = 0, curr = 0;
  std::size_t count = 0, length = 0;

  while (true) {
    std::cin >> curr;

    if (std::cin.bad() || std::cin.fail()) {
      std::cerr << "Invalid argument\n";
      return code_invalid_input;
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

  if (length < min_length_of_seq) {
    std::cerr << "Too short\n";
    return code_too_short_seq;
  }

  std::cout << count << std::endl;
}
