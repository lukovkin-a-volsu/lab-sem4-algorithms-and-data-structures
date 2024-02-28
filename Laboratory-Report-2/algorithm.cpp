#include "algorithm.h"

const char *format_out(int out)
{
  return (out == 0 ? "Не монотонна" : out == 1 ? "Монотонно возрастает"
                                               : "Монотонно убывает");
}

template <class T>
int is_monotonous(T *data, int n, double &ms)
{
  int increase = 0, decrease = 0, res = 0;
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 1; i < n; i++)
  {
    if (data[i] > data[i - 1])
    {
      increase++;
    }
    else if (data[i] < data[i - 1])
    {
      decrease++;
    }

    if (increase != 0 && decrease != 0)
    {
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> time_elapsed = end - start;
      ms = time_elapsed.count() * 1000;
      return res;
    }
  }

  if (increase == 0 && decrease == 0)
  {
    res = 0;
  }
  else if (increase > 0)
  {
    res = 1;
  }
  else
  {
    res = -1;
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time_elapsed = end - start;
  ms = time_elapsed.count() * 1000;
  return res;
}