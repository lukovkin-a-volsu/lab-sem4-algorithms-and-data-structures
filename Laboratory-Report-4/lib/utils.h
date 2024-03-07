#ifndef UTILS_H
#define UTILS_H

#include <iostream>

using std::cout;
using std::endl;

template <class T>
void out_arr(T *, size_t);

template <class T>
void out_arr(T *arr, size_t n)
{
    cout << " ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#endif // UTILS_H
