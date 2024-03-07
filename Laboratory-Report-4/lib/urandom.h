#ifndef URANDOM_H
#define URANDOM_H

#include <chrono>
#include <random>

#ifndef RND_MIN
#define RND_MIN -10000
#endif
#ifndef RND_MAX
#define RND_MAX 10000
#endif

std::default_random_engine generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());

template <class T>
T *rand_arr(size_t);

template <class T>
T *rand_arr(size_t n)
{
    double random;
    std::uniform_real_distribution<double> dist(RND_MIN, RND_MAX);
    T *arr = new T[n];
    for (size_t i = 0; i < n; i++)
    {
        random = dist(generator);
        T val = (T)random;
        arr[i] = val;
    }
    return arr;
}

#endif // URANDOM_H
