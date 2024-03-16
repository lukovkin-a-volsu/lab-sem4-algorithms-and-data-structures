#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include "ustruct.h"

using std::cout;
using std::endl;

template <class T>
class Deque
{
private:
    T **arr;
    int _head;
    int _tail;
    int _size;

    void _normalize()
    {
        // if (_tail > _head)
        // {
        //     int tmp = _tail;
        //     _tail = _head;
        //     _head = tmp;
        // }
    }

    void _allocate()
    {
        _size = (_tail - _head) + 1;
        int new_size = _size * 2;
        T **new_arr = new T *[new_size];
        for (int i = 0; i < _size; ++i)
        {
            new_arr[i] = arr[_head + i]; // Смещение индекса для head
        }
        _tail = oldSize - 1;
        _head = 0;

        // _tail -= _head;
        // _head = 0;
        arr = new_arr;
        _size = new_size;
    }

public:
    // const static void (*push_front)(T) = push;
    // const static void (*push_back)(T) = unshift;
    // const static void (*pop_front)(T) = pop;
    // const static void (*pop_back)(T) = shift;
    // const static void (*peek)(T) = unshift;
    // const static void (*top)(T) = unshift;
    // const static void (*append)(T) = push;

    Deque(T data)
    {
        arr = new T *[1];
        T *data_ptr = new T;
        *data_ptr = data;
        arr[0] = data_ptr;
        _head = 0;
        _tail = 0;
        _size = 1;
    }

    ~Deque()
    {
        delete[] arr;
    }

    // add on the right
    void push_back(T data)
    {
        if (_tail + 1 >= _size)
            _allocate();
        T *data_ptr = new T;
        *data_ptr = data;
        arr[++_tail] = data_ptr;
        _normalize();
    }

    // rem on the right
    T pop_back()
    {
        T el = *(arr[_tail]);
        arr[_tail] = NULL; // or null?
        _tail--;
        _normalize();
        return el;
    }

    // add on the left
    void push_front(T data)
    {
        T *data_ptr = new T;
        *data_ptr = data;
        if (_head > 0)
        {
            arr[--_head] = data_ptr;
            return;
        }
        if (_tail + 1 >= _size)
            _allocate();
        for (int i = _head + 1; i <= _tail + 1; i++)
        {
            arr[i] = arr[i - 1];
        }
        arr[_head] = data_ptr;
        _tail++;
    }

    // rem on the left
    T pop_front()
    {
        T el = *(arr[_head]);
        arr[_head++] = nullptr;
        _normalize();
        return el;
    }

    void print()
    {
        cout << "\n-----" << endl;
        for (int i = _head; i <= _tail; i++)
        {
            cout << i << " element: " << *arr[i] << endl;
        }
        cout << "-----\n"
             << endl;
    }

    void print_memory()
    {
        cout << "\n-----" << endl;
        for (int i = _head; i <= _tail; i++)
        {
            cout << i << " element: " << arr[i] << endl;
        }
        cout << "-----\n"
             << endl;
    }

    void print_all()
    {
        cout << "\n-----" << endl;
        for (int i = 0; i < _size; i++)
        {
            cout << i << " element: " << *arr[i] << endl;
        }
        cout << "-----\n"
             << endl;
    }
};

#endif // DEQUE_H
