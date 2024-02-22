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
  clock_t start = clock();

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
      ms = clock() - start;
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

  ms = clock() - start;
  return res;
}