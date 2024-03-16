#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>
#include "ustruct.h"

using std::cout;
using std::endl;

template <class T>
class CircularLinkedList
{
private:
    TNode<T> *head;

public:
    CircularLinkedList(T data)
    {
        head = new TNode<T>;
        head->data = data;
        head->next = head;
    }

    ~CircularLinkedList()
    {
        TNode<T> *cur = head;
        while (cur != nullptr)
        {
            TNode<T> *next = cur->next;
            delete cur;
            cur = next;
        }
        head = nullptr;
    }

    void add(T data)
    {
        TNode<T> *new_node = new TNode<T>;
        new_node->data = data;
        // if the list is empty
        if (head == nullptr)
        {
            head = new_node;
            head->next = new_node;
            return;
        }
        TNode<T> *tmp = head;
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
        new_node->next = head;
    }

    void print()
    {
        if (head == nullptr)
            return;
        TNode<T> *cur = head;
        cout << "\n-----" << endl;
        int num = 0;
        do
        {
            cout << "Node " << ++num << ": " << cur->data << endl;
            cur = cur->next;
        } while (cur != head);
        cout << "-----\n"
             << endl;
    }

    void print_memory()
    {
        if (head == nullptr)
            return;
        TNode<T> *cur = head;
        cout << "\n-----" << endl;
        int num = 0;
        do
        {
            cout << "Node " << ++num << ": " << cur << ". Next node: " << cur->next << endl;
            cur = cur->next;
        } while (cur != head);
        cout << "-----\n"
             << endl;
    }

    void remove(T data)
    {
        if (head == nullptr)
            return;
        if (head->next == head)
        {
            // cout << "The list contains only one element" << endl;
            delete head;
            return;
        }
        TNode<T> *prev = nullptr;
        TNode<T> *cur = head;
        do
        {
            if (cur->data == data)
            {
                if (cur == head)
                {
                    TNode<T> *last_node = head;
                    while (last_node->next != head)
                    {
                        last_node = last_node->next;
                    }
                    last_node->next = head->next;
                    head = last_node;
                }
                else
                {
                    prev->next = cur->next;
                }

                // cout << cur->data << " deleted successfully." << endl;
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        } while (cur != nullptr);
        // cout << "Nothing to delete" << endl;
    }

    TNode<T> *get(T data)
    {
        if (head == nullptr)
            return nullptr;
        TNode<T> *tmp = new TNode<T>;
        tmp = head;

        do
        {
            if (tmp->data == data)
                return tmp;
            tmp = tmp->next;
        } while (tmp != head);
        return nullptr;
    }

    void (CircularLinkedList<T>::*push_front)(T) = &add;
    void (CircularLinkedList<T>::*pop_back)(T) = &remove;
};

#endif // CIRCULAR_LINKED_LIST_H