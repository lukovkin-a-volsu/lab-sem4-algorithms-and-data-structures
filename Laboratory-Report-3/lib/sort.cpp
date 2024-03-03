#include "sort.h"

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

template <class T>
void cocktail_sort(T *&arr, size_t n, double &ms)
{
    bool is_swapped = true;
    int l = 0, r = n - 1;
    auto start = std::chrono::high_resolution_clock::now();
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_elapsed = end - start;
    ms = time_elapsed.count() / 1000;
}