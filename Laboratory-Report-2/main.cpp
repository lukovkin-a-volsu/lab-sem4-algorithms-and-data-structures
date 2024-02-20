#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "algorithm"

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

    return 0;
}

template <class T, int n>
T *rand_arr()
{
    double random;
    srand((unsigned)time(NULL));
    T *array = new T[n];
    for (int i = 0; i < n; i++)
    {
        random = (double) rand() / rand();
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
