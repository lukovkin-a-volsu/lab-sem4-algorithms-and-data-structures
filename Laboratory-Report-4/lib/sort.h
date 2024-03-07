#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <chrono>
#include "urandom.h"

using std::cout;
using std::endl;

template <class T>
void cocktail_sort(T *&, size_t);

template <class T>
void cocktail_sort(T *&arr, size_t n)
{
  bool is_swapped = true;
  int l = 0, r = n - 1;
  while (is_swapped)
  {
    is_swapped = false;

    for (size_t i = l; i < r; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        T tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        is_swapped = true;
      }
    }
    r--;

    for (size_t i = r; i > l; i--)
    {
      if (arr[i] < arr[i - 1])
      {
        T tmp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = tmp;
        is_swapped = true;
      }
    }
    l++;
  }
}

#endif