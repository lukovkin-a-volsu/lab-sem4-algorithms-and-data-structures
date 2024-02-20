#include <random>
#include <stdlib.h>
#include "algorithm.h"

#ifndef RAND_MIN
#define RAND_MIN -100000
#endif
#ifndef RAND_MAX
#define RAND_MAX 100000
#endif

using std::cout;
using std::endl;

template <class T, int n>
T *rand_arr();
template <class T, int n>
void print_arr(T *arr);

int main()
{
    double *arr = rand_arr<double, 10>();
    print_arr<double, 10>(arr);
    cout << format_out(is_monotonous<double *, 10>(arr)) << endl;

    return 0;
}

template <class T, int n>
T *rand_arr()
{
    double random;
    std::mt19937 gen;
    std::uniform_real_distribution<> dist(RAND_MIN, RAND_MAX);
    T *array = new T[n];
    for (int i = 0; i < n; i++)
    {
        random = dist(gen);
        T value = (T)random;
        array[i] = value;
    }
    return array;
}

template <class T, int n>
void print_arr(T *arr)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}