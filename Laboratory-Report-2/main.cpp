#include <stdlib.h>
#include <random>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <iostream>
#include "algorithm.h"

#ifndef RND_MIN
#define RND_MIN -100
#endif
#ifndef RND_MAX
#define RND_MAX 100
#endif

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ofstream;
using std::setprecision;
using std::string;

std::default_random_engine generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());

bool menu();

template <class T>
void auto_test(ofstream &out);

// T - array type, n - array size
template <class T>
void test(int times, int n, double &avg_ms);

template <class T>
T *rand_arr(int n);

int main()
{
    bool is_continue;
    do
    {
        is_continue = menu();
    } while (is_continue);
    return 0;
}

bool menu()
{
    ofstream out;
    string filename;
    string dtype;
    cout << "Input filename or 0 (exit): " << endl;
    getline(cin, filename);

    if (filename.compare("0") == 0)
    {
        cout << "Exit." << endl;
        return false;
    }

    out.open(filename);

    cout << "Input data type "
         << "(d - double, i - int, l - long, f - float, s - short)"
         << ": " << endl;
    getline(cin, dtype);

    if (dtype.compare("d") == 0)
    {
        auto_test<double>(out);
    }
    else if (dtype.compare("l") == 0)
    {
        auto_test<long>(out);
    }
    else if (dtype.compare("f") == 0)
    {
        auto_test<float>(out);
    }
    else if (dtype.compare("s") == 0)
    {
        auto_test<short>(out);
    }
    else
    {
        auto_test<int>(out);
    }

    out.close();
    return true;
}

template <class T>
void auto_test(ofstream &out)
{
    double avg_ms;
    int times = 100;
    int n_arr[]{1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};

    for (int n : n_arr)
    {
        test<T>(times, n, avg_ms);
        cout << "N: " << n << "; T: " << avg_ms << " ms." << endl;
        out << n << ";" << avg_ms << endl;
    }
}

template <class T>
void test(int times, int n, double &avg_ms)
{
    avg_ms = 0;
    for (int i = 0; i < times; i++)
    {
        double ms = 0;
        T *arr = rand_arr<T>(n);
        is_monotonous<T>(arr, n, ms);
        avg_ms += ms;
    }
    avg_ms /= times;
}

template <class T>
T *rand_arr(int n)
{
    double random;
    std::uniform_real_distribution<double> dist(RND_MIN, RND_MAX);
    T *arr = new T[n];
    for (int i = 0; i < n; i++)
    {
        random = dist(generator);
        T val = (T)random;
        arr[i] = val;
    }
    return arr;
}