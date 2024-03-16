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
        int new_size = _size * 2;
        T **new_arr = new T *[new_size];
        for (int i = 0; i < new_size; ++i)
        {
            new_arr[i] = nullptr;
        }
        for (int i = _head, j = 0; i <= _tail; ++i, ++j)
        {
            new_arr[j] = arr[i];
        }
        arr = new_arr;
        _size = new_size;
        _head = 0;
        _tail = _tail - _head;
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

    bool empty()
    {
        return _head > _tail;
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
        if (empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        T el = *(arr[_tail]);
        arr[_tail] = nullptr; // or null?
        _tail--;
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
        for (int i = _tail + 1; i >= _head; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[_head] = data_ptr;
        _tail++;
    }

    // rem on the left
    T pop_front()
    {
        if (empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        T el = *(arr[_head]);
        arr[_head++] = nullptr;
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
            if (arr[i] == nullptr)
            {
                cout << i << "element: nullptr" << endl;
            }
            else
            {
                cout << i << " element: " << *arr[i] << endl;
            }
        }
        cout << "-----\n"
             << endl;
    }
};

#endif // DEQUE_H
