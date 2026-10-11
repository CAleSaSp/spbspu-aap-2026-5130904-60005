#include <iostream>

namespace usmanov
{
  void runLab1()
  {
    long long num = 0;
    long long minElement = 0;
    long long countMin = 0;
    bool hasElements = false;
    long long prev1 = 0;
    long long prev2 = 0;
    long long countLocMin = 0;
    unsigned long long sequenceLength = 0;

    std::cerr << "Введите числа (0 для конца):\n";

    while (std::cin >> num)
    {
      if (num == 0)
      {
        break;
      }

      if (!hasElements)
      {
        minElement = num;
        countMin = 1;
        hasElements = true;
      }
      else if (num < minElement)
      {
        minElement = num;
        countMin = 1;
      }
      else if (num == minElement)
      {
        countMin++;
      }

      sequenceLength++;
      if (sequenceLength >= 3)
      {
        if (prev1 < prev2 && prev1 < num)
        {
          countLocMin++;
        }
      }
      prev2 = prev1;
      prev1 = num;
    }

    if (!std::cin.eof() && std::cin.fail())
    {
      std::cerr << "Ошибка: Некорректный ввод.\n";
      std::exit(1);
    }

    if (!hasElements)
    {
      std::cout << 0 << "\n";
    }
    else
    {
      std::cout << countMin << "\n";
    }

    if (sequenceLength == 0)
    {
      std::cerr << "Ошибка: Мало элементов.\n";
      std::exit(2);
    }

    std::cout << countLocMin << "\n";
  }
}

int main()
{
  usmanov::runLab1();
  return 0;
}
