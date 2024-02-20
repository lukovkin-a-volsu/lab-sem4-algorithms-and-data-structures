#include "algorithm.h"

const char *format_out(int out)
{
  return (out == 0 ? "Не монотонна" : out == 1 ? "Монотонно возрастает"
                                               : "Монотонно убывает");
}

template <class T, int n>
int is_monotonous(T data)
{
  int increase = 0, decrease = 0;

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
      return 0;
    }
  }

  if (increase == 0 && decrease == 0)
  {
    return 0;
  }
  else if (increase > 0)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}