#include <iostream>

using std::cout;
using std::endl;

template <class T, int n>
int is_monotonous(T data);
void test();

int main()
{
  test();
  return 0;
}

void test()
{
  int *a;

  a = new int[3]{1,
                 2,
                 2};
  cout << is_monotonous<int *, 3>(a)
       << endl; // 1
  delete[] a;

  a = new int[3]{1,
                 2,
                 3};
  cout << is_monotonous<int *, 3>(a)
       << endl; // 1
  delete[] a;

  a = new int[3]{2,
                 2,
                 2};
  cout << is_monotonous<int *, 3>(a)
       << endl; // 0
  delete[] a;

  a = new int[3]{3,
                 2,
                 2};
  cout << is_monotonous<int *, 3>(a)
       << endl; // -1
  delete[] a;

  a = new int[3]{3,
                 2,
                 1};
  cout << is_monotonous<int *, 3>(a)
       << endl; // -1
  delete[] a;

  double *b;

  b = new double[5]{
      1,
      2.3,
      2.3,
      2.4,
      2.6};
  cout << is_monotonous<double *, 5>(b)
       << endl; // 1
  delete[] b;

  b = new double[5]{
      1,
      2.3,
      2.3,
      2.2,
      2.4};
  cout << is_monotonous<double *, 5>(b)
       << endl; // 0
  delete[] b;

  b = new double[5]{
      3,
      2.3,
      2.2,
      2.1,
      1.4};
  cout << is_monotonous<double *, 5>(b)
       << endl; // -1
  delete[] b;
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