#include <string>
#include "lib/circular_linked_list.h"
#include "lib/deque.h"
#include "lib/timer.h"

using std::cin;
using std::string;

template <class T>
bool circular_linked_list_menu(CircularLinkedList<T> *list);

template <class T>
bool deque_menu(Deque<T> *deque);

int main()
{
    CircularLinkedList<int> *list = new CircularLinkedList<int>(0);

    cout << "CIRCULAR LINKED LIST" << endl;
    bool is_continue_1;
    do
    {
        is_continue_1 = circular_linked_list_menu<int>(list);
    } while (is_continue_1);

    Deque<int> *deq = new Deque<int>(0);
    cout << "DEQUE" << endl;

    bool is_continue_2;
    do
    {
        is_continue_2 = deque_menu<int>(deq);
    } while (is_continue_2);

    size_t n = 5;
    size_t n_arr[]{100, 1000, 2000, 3000, 5000};
    test_deque<int>(n_arr, n);
    test_circular_linked_list<int>(n_arr, n);
}

template <class T>
bool circular_linked_list_menu(CircularLinkedList<T> *list)
{
    int action;
    T value;
    TNode<T> *el;

    cout << endl;
    cout << "Circular Linked List" << endl;
    cout << "Actions:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Get" << endl;
    cout << "4. Print memory" << endl;
    cout << "5. Print" << endl;
    cout << ": ";

    cin >> action;

    switch (action)
    {
    case 1:
        cout << "Element value: ";
        cin >> value;
        list->add(value);
        break;
    case 2:
        cout << "Element value: ";
        cin >> value;
        list->remove(value);
        break;
    case 3:
        cout << "Element value: ";
        cin >> value;
        el = list->get(value);
        if (el == nullptr)
        {
            cout << "Element not found" << endl;
        }
        else
        {
            cout << "Element value: " << el->data << endl;
        }
        break;
    case 4:
        list->print_memory();
        break;
    case 5:
        list->print();
        break;
    default:
        cout << endl;
        return false;
    }

    int response;
    cout << endl
         << "Continue? 1 - Yes: ";
    cin >> response;
    if (response == 1)
    {
        return true;
    }
    return false;
}

template <class T>
bool deque_menu(Deque<T> *deque)
{
    int action;
    T value;

    cout << endl;
    cout << "Deque" << endl;
    cout << "Actions:" << endl;
    cout << "1. Push back" << endl;
    cout << "2. Pop back" << endl;
    cout << "3. Push front" << endl;
    cout << "4. Pop front" << endl;
    cout << "5. Print memory" << endl;
    cout << "6. Print all" << endl;
    cout << "7. Print" << endl;
    cout << ": ";

    cin >> action;

    switch (action)
    {
    case 1:
        cout << "Element value: ";
        cin >> value;
        deque->push_back(value);
        break;
    case 2:
        cout << "Element: " << deque->pop_back() << endl;
        break;
    case 3:
        cout << "Element value: ";
        cin >> value;
        deque->push_front(value);
        break;
    case 4:
        cout << "Element: " << deque->pop_front() << endl;
        break;
    case 5:
        deque->print_memory();
        break;
    case 6:
        deque->print_all();
        break;
    case 7:
        deque->print();
        break;
    default:
        cout << endl;
        return false;
    }

    int response;
    cout << endl
         << "Continue? 1 - Yes: ";
    cin >> response;
    if (response == 1)
    {
        return true;
    }
    return false;
}