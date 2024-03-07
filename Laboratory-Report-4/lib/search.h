#ifndef SEARCH_H
#define SEARCH_H

#include "alias.h"

template <class T>
int linear_search(T *, size_t, T);
template <class T>
int binary_search(T *, size_t, T);
template <class T>
int fibonacci_search(T *, size_t, T);
template <class T>
int interpolation_search(T *, size_t, T);

template <class T>
int linear_search(T *arr, size_t n, T key)
{
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// O(log n)
template <class T>
int binary_search(T *arr, size_t n, T key)
{
    int l = 0;
    int r = n - 1;
    int m;

    while (l <= r)
    {
        m = (r + l) / 2;
        T value = arr[m];

        if (value > key)
        {
            r = m - 1;
        }
        else if (value < key)
        {
            l = m + 1;
        }
        else
        {
            return m;
        }
    }

    return -1;
}

// O(log n)
template <class T>
int fibonacci_search(T *arr, size_t n, T key)
{
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;
    int shift = -1;

    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    while (fib > 1)
    {
        int i = fib2 + shift;
        if (n - 1 < i)
        {
            i = n - 1;
        }

        if (arr[i] > key)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else if (arr[i] < key)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            shift = i;
        }
        else
        {
            return i;
        }
    }

    if (fib1 && arr[shift + 1] == key)
        return shift + 1;

    return -1;
}

// O(log (log n))
template <class T>
int interpolation_search(T *arr, size_t n, T key)
{
    int l = 0;
    int r = n - 1;
    int m;

    while (arr[l] < key && arr[r] > key)
    {
        if (arr[l] == arr[r])
            break;

        m = l + ((key - arr[l]) * (r - l)) / (arr[r] - arr[l]);
        T value = arr[m];

        if (value > key)
        {
            r = m - 1;
        }
        else if (value < key)
        {
            l = m + 1;
        }
        else
        {
            return m;
        }
    }

    if (arr[l] == key)
        return l;
    if (arr[r] == key)
        return r;

    return -1;
}

#endif // SEARCH_H
