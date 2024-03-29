#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <fstream>
#include "alias.h"
#include "urandom.h"
#include "sort.h"

using std::cout;
using std::endl;
using std::function;
using std::ofstream;
using std::string;

template <class T>
void auto_test(string, size_t[], size_t, search_function<T>, bool);
template <class T>
void test(int, size_t, search_function<T>, bool, double &);

template <class T>
void auto_test(string filename, size_t n_arr[], size_t len, search_function<T> f, bool is_sorted)
{
    ofstream out(filename);

    double avg_ms;
    int times = 500;

    cout << filename << endl;
    for (size_t i = 0; i < len; i++)
    {
        int n = n_arr[i];
        test<T>(times, n, f, is_sorted, avg_ms);
        cout << "N: " << n << "; T: " << avg_ms << " ms." << endl;
        out << n << ";" << avg_ms << endl;
    }
    cout << endl;

    out.close();
}

template <class T>
void test(int times, size_t n, search_function<T> f, bool is_sorted, double &avg_ms)
{
    avg_ms = 0;
    double total_duration = 0;
    for (size_t i = 0; i < times; i++)
    {
        double ms = 0;
        T *arr = rand_arr<T>(n);
        std::uniform_real_distribution<double> dist(0, n - 1);
        size_t rand_i = dist(generator);
        T key = arr[rand_i];
        if (is_sorted)
        {
            cocktail_sort(arr, n);
        }
        auto start_time = std::chrono::high_resolution_clock::now();
        f(arr, n, key);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        total_duration += duration;
    }
    avg_ms = total_duration / (times * 1e6);
}

#endif // TIMER_H