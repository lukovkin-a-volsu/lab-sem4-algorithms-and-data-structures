#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <chrono>
#include <iostream>

using std::cout;
using std::endl;

const char *format_out(int out);
template <class T>
int is_monotonous(T data, int n, double &ms); 

#include "algorithm.cpp"

#endif