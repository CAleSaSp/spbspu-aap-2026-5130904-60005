#include <cstddef>
#include <iostream>

namespace adel
{
  struct Result
  {
    std::size_t count;
    int subMax;
    std::size_t locMax;
  };

  bool readSequence(std::istream & in, Result & res)
  {
    res.count = 0;
    res.subMax = 0;
    res.locMax = 0;

    int max = 0;
    int prevPrev = 0;
    int prev = 0;
    int x = 0;

    while (in >> x)
    {
      if (x == 0)
      {
        return true;
      }

      if (res.count >= 2 && prev > prevPrev && prev > x)
      {
        ++res.locMax;
      }

      if (res.count == 0)
      {
        max = x;
      }
      else if (x > max)
      {
        res.subMax = max;
        max = x;
      }
      else if (res.count == 1 || x > res.subMax)
      {
        res.subMax = x;
      }

      prevPrev = prev;
      prev = x;
      ++res.count;
    }
    return false;
  }
}

int main()
{
  adel::Result res;
  if (!adel::readSequence(std::cin, res))
  {
    std::cerr << "Error: input is not a valid sequence\n";
    return 1;
  }

  int code = 0;

  if (res.count < 2)
  {
    std::cerr << "Error: sequence is too short for SUB-MAX\n";
    code = 2;
  }
  else
  {
    std::cout << res.subMax << '\n';
  }

  if (res.count < 1)
  {
    std::cerr << "Error: sequence is too short for LOC-MAX\n";
    code = 2;
  }
  else
  {
    std::cout << res.locMax << '\n';
  }

  return code;
}
