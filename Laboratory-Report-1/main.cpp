#include <iostream>
#include <random>
#include <chrono>

#ifndef RND_MIN
#define RND_MIN -100
#endif
#ifndef RND_MAX
#define RND_MAX 100
#endif

using std::cin;
using std::cout;
using std::endl;

template <class T, int n>
int is_monotonous(T data);
template <class T, int n>
void test();

std::default_random_engine generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
  test<int, 5>();
  test<int, 10>();
  test<double, 5>();
  test<double, 10>();
  return 0;
}

template <class T, int n>
void test()
{
  T *arr = new T[n];
  cout << "Array: " << endl;
  for (int i = 0; i < n; i++)
  {
    std::uniform_real_distribution<double> dist(RND_MIN, RND_MAX);
    T rand_num = (T)dist(generator);
    arr[i] = rand_num;
    cout << arr[i] << " ";
  }

  cout << endl;
  cout << "Result: ";
  cout << is_monotonous<T *, 10>(arr) << endl
       << endl;
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