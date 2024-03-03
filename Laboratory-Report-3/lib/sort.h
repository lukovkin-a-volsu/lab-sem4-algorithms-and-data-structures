#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <chrono>
#include <random>
#include "urandom.h"

using std::cout;
using std::endl;

template <class T>
void out_arr(T *, size_t);
template <class T>
T *rand_arr(size_t);
template <class T>
void cocktail_sort(T *&, size_t, double &);

#include "sort.cpp"

#endif