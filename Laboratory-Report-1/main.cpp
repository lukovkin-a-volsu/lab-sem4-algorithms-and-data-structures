#include <iostream>

using std::cout;
using std::endl;

template <class T, int n>
int is_monotonous(T data);

int main()
{
  int a[] = {1,
             2,
             2};

  int res = is_monotonous<int *, 3>(a);
  cout << res << endl;
  return 0;
}

template <class T, int n>
int is_monotonous(T data)
{
  int increase, decrease = 0;
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
      return 0;
  }

  return (increase == 0 && decrease == 0) ? 0 : increase > 0 ? 1
                                                             : -1;
}