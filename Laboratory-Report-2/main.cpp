#include <stdlib.h>
#include <random>
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
using std::setprecision;

std::default_random_engine generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());

// T - array type, n - array size
template <class T, int n>
void test(int times, double &ms);

template <class T, int n>
T *rand_arr();

template <class T, int n>
void print_arr(T *arr);

int main()
{
    double avg_ms;
    double max_avg_ms = 0;
    int times = 1000;

    // 1
    test<double, 1000>(times, avg_ms);
    cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    max_avg_ms += avg_ms;
    
    // 2
    test<double, 2000>(times, avg_ms);
    cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    max_avg_ms += avg_ms;
    
    // 3
    test<double, 5000>(times, avg_ms);
    cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    max_avg_ms += avg_ms;
    
    // 4
    test<double, 10000>(times, avg_ms);
    cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    max_avg_ms += avg_ms;
    
    // 5
    test<double, 20000>(times, avg_ms);
    cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    max_avg_ms += avg_ms;
    
    // 6
    test<double, 50000>(times, avg_ms);
    cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    max_avg_ms += avg_ms;
    
    // 7
    test<double, 100000>(times, avg_ms);
    cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    max_avg_ms += avg_ms;
    
    // 8
    test<double, 200000>(times, avg_ms);
    cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    max_avg_ms += avg_ms;
    
    // 9
    test<double, 500000>(times, avg_ms);
    cout << fixed << setprecision(10) << avg_ms << " ms." << endl;
    max_avg_ms += avg_ms;
    
    cout << fixed << setprecision(10) << max_avg_ms << " max ms." << endl;
    return 0;
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

template <class T, int n>
void print_arr(T *arr)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}