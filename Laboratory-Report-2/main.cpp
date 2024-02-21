#include <stdlib.h>
#include <random>
#include <fstream>
#include <iomanip>
#include "algorithm.h"

#ifndef RAND_MIN
#define RAND_MIN -100000
#endif
#ifndef RAND_MAX
#define RAND_MAX 100000
#endif

using std::cout;
using std::endl;
using std::fixed;
using std::ofstream;
using std::setprecision;

std::default_random_engine generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());

template <class T>
void auto_test(ofstream &out);

// T - array type, n - array size
template <class T, int n>
void test(int times, double &avg_ms);

template <class T, int n>
T *rand_arr();

int main()
{
    ofstream out;

    // out.open("double_test_1.txt");
    // auto_test<double>(out);
    // out.close();

    // out.open("float_test_1.txt");
    // auto_test<float>(out);
    // out.close();

    // out.open("long_test_1.txt");
    // auto_test<long>(out);
    // out.close();

    // out.open("int_test_1.txt");
    // auto_test<int>(out);
    // out.close();

    out.open("short_test_1.txt");
    auto_test<short>(out);
    out.close();

    return 0;
}

template <class T>
void auto_test(ofstream &out)
{
    double avg_ms;
    double max_avg_ms = 0;
    int times = 1000;
    int n_arr[]{1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};

    test<T, 1000>(times, avg_ms);
    // cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    out << 1000 << ";" << avg_ms << endl;
    // max_avg_ms += avg_ms;

    test<T, 2000>(times, avg_ms);
    // cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    out << 2000 << ";" << avg_ms << endl;
    // max_avg_ms += avg_ms;

    test<T, 5000>(times, avg_ms);
    // cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    out << 5000 << ";" << avg_ms << endl;
    // max_avg_ms += avg_ms;

    test<T, 10000>(times, avg_ms);
    // cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    out << 10000 << ";" << avg_ms << endl;
    // max_avg_ms += avg_ms;

    test<T, 20000>(times, avg_ms);
    // cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    out << 20000 << ";" << avg_ms << endl;
    // max_avg_ms += avg_ms;

    test<T, 50000>(times, avg_ms);
    // cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    out << 50000 << ";" << avg_ms << endl;
    // max_avg_ms += avg_ms;

    test<T, 100000>(times, avg_ms);
    // cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    out << 100000 << ";" << avg_ms << endl;
    // max_avg_ms += avg_ms;

    test<T, 200000>(times, avg_ms);
    // cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    out << 200000 << ";" << avg_ms << endl;
    // max_avg_ms += avg_ms;

    test<T, 500000>(times, avg_ms);
    // cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    out << 500000 << ";" << avg_ms << endl;
    // max_avg_ms += avg_ms;

    // cout << fixed << setprecision(10) << max_avg_ms << " max ms." << endl;
}

template <class T, int n>
void test(int times, double &avg_ms)
{
    avg_ms = 0;
    for (int i = 0; i < times; i++)
    {
        double ms = 0;
        T *arr = rand_arr<T, n>();
        is_monotonous<T, n>(arr, ms);
        avg_ms += ms;
    }
    avg_ms /= times;
}

template <class T, int n>
T *rand_arr()
{
    double random;
    // compile generator
    // std::mt19937 generator;
    std::uniform_real_distribution<double> dist(RAND_MIN, RAND_MAX);
    T *arr = new T[n];
    for (int i = 0; i < n; i++)
    {
        random = dist(generator);
        T val = (T)random;
        arr[i] = val;
    }
    return arr;
}