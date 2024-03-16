#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <fstream>
#include <functional>
#include "deque.h"
#include "circular_linked_list.h"
#include "urandom.h"

using std::cout;
using std::endl;
using std::function;
using std::ofstream;
using std::string;

template <class T>
void test_deque(size_t n_arr[], size_t n);
template <class T>
void test_circular_linked_list(size_t n_arr[], size_t n);

template <class T>
void test_deque(size_t n_arr[], size_t n)
{

    std::uniform_real_distribution<double> dist(RND_MIN, RND_MAX);

    ofstream out1("deque_insertion.txt");
    cout << "deque_insertion" << endl;
    int times1 = 200;
    for (int i = 0; i < n; i++)
    {
        double avg_ms = 0;
        double total_duration = 0;
        int size = n_arr[i];
        for (int j = 0; j < times1; ++j)
        {
            Deque<T> *deque = new Deque<T>(0);
            for (int k = 0; k < size; k++)
            {
                T rand_val = dist(generator);
                auto start_time = std::chrono::high_resolution_clock::now();
                deque->push_back(rand_val);
                auto end_time = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
                total_duration += duration;
            }
        }
        avg_ms = total_duration / (times1 * 1e6);
        cout << size << ";" << avg_ms << " ms." << endl;
        out1 << size << ";" << avg_ms << endl;
    }
    out1.close();

    ofstream out2("deque_removing.txt");
    cout << "deque_removing" << endl;
    const int times2 = 200;
    for (int i = 0; i < n; i++)
    {
        double avg_ms = 0;
        double total_duration = 0;
        int size = n_arr[i];
        for (int j = 0; j < times2; ++j)
        {
            Deque<T> *deque = new Deque<T>(0);
            for (int k = 0; k < size; k++)
            {
                T rand_val = dist(generator);
                deque->push_back(rand_val);
                auto start_time = std::chrono::high_resolution_clock::now();
                deque->pop_back();
                auto end_time = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
                total_duration += duration;
            }
        }
        avg_ms = total_duration / (times1 * 1e6);
        cout << size << ";" << avg_ms << " ms." << endl;
        out2 << size << ";" << avg_ms << endl;
    }
    out2.close();
}

template <class T>
void test_circular_linked_list(size_t n_arr[], size_t n)
{

    std::uniform_real_distribution<double> dist(RND_MIN, RND_MAX);

    ofstream out1("circular_linked_list_insertion.txt");
    const int times1 = 200;
    cout << "circular_linked_list_insertion" << endl;
    for (int i = 0; i < n; i++)
    {
        double avg_ms = 0;
        double total_duration = 0;
        int size = n_arr[i];
        for (int j = 0; j < times1; ++j)
        {
            CircularLinkedList<T> *list = new CircularLinkedList<T>(0);
            for (int k = 0; k < size; k++)
            {
                T rand_val = dist(generator);
                auto start_time = std::chrono::high_resolution_clock::now();
                list->add(rand_val);
                auto end_time = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
                total_duration += duration;
            }
        }
        avg_ms = total_duration / (times1 * 1e6);
        cout << size << ";" << avg_ms << " ms." << endl;
        out1 << size << ";" << avg_ms << endl;
    }
    out1.close();

    ofstream out2("circular_linked_list_removing.txt");
    const int times2 = 10;
    cout << "circular_linked_list_removing" << endl;
    for (int i = 0; i < n; i++)
    {
        double avg_ms = 0;
        double total_duration = 0;
        int size = n_arr[i];
        for (int j = 0; j < times1; ++j)
        {
            CircularLinkedList<T> *list = new CircularLinkedList<T>(0);

            std::uniform_real_distribution<double> dist2(1, size - 1);
            int key_index = (int)dist2(generator);
            T key;
            for (int l = 0; l < size; l++)
            {
                T rand_val = dist(generator);
                if (l == key_index)
                    key = rand_val;
                list->add(rand_val);
            }

            for (int k = 0; k < size; k++)
            {

                auto start_time = std::chrono::high_resolution_clock::now();
                list->remove(key);
                auto end_time = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
                list->add(key);
                total_duration += duration;
            }
        }
        avg_ms = total_duration / (times1 * 1e6);
        cout << size << ";" << avg_ms << " ms." << endl;
        out2 << size << ";" << avg_ms << endl;
    }
    out2.close();
}

#endif // TIMER_H