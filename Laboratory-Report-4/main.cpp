#include <conio.h>
#include <functional>
#include "lib/urandom.h"
#include "lib/utils.h"
#include "lib/timer.h"
#include "lib/sort.h"
#include "lib/search.h"
#include "lib/student.h"
#include "lib/alias.h"

using std::cin;
using std::string;

bool menu();
template <class T>
void search_test(T *, size_t, T);

int main()
{
	bool is_working;

	do
	{
		// 2. if true
		is_working = menu();
	} while (is_working);

	return 0;
}

bool menu()
{
	size_t n;
	int key;
	int *arr;
	string s_group;
	Student *s_arr;
	Student s_key;
	double ms;

	// cout << "1. and 2." << endl;
	// cout << "Input array size: ";
	// cin >> n;
	// arr = rand_arr<int>(n);
	// cout << "Array: " << endl;
	// out_arr(arr, n);
	// cout << "Input key: ";
	// cin >> key;
	// search_test(arr, n, key);

	// cout << "3." << endl;
	// cout << "Input array size: ";
	// cin >> n;
	// s_arr = Student::get_rand_student_array(n);
	// cout << "Array: " << endl;
	// out_arr(s_arr, n);
	// cout << "Input key (group): ";
	// cin >> s_group;
	// s_key = Student(s_group);
	// search_test(s_arr, n, s_key);

	getch();
	
	cout << "4." << endl;
	// length of testing arrays
	size_t len = 5;
	size_t n_arr[]{100, 1000, 2000, 3000, 5000};
	auto_test<int>("linear_int.txt", n_arr, len, linear_search<int>, false);
	// auto_test<double>("linear_double.txt", n_arr, len, linear_search<double>, false);
	auto_test<int>("binary_int.txt", n_arr, len, binary_search<int>, true);
	// auto_test<double>("binary_double.txt", n_arr, len, binary_search<double>, true);
	auto_test<int>("fibonacci_int.txt", n_arr, len, fibonacci_search<int>, true);
	// auto_test<double>("fibonacci_double.txt", n_arr, len, fibonacci_search<double>, true);
	auto_test<int>("interpolation_int.txt", n_arr, len, interpolation_search<int>, true);
	// auto_test<double>("interpolation_double.txt", n_arr, len, interpolation_search<double>, true);

	string response;
	cout << endl
		 << "Continue? Y/N: ";
	cin >> response;
	if (response == "N")
	{
		return false;
	}

	return true;
}

template <class T>
void search_test(T *arr, size_t n, T key)
{
	if (n <= 0)
		return;

	double ms;

	cout << "Key index (-1 if no found)." << endl;
	cout << "A)" << endl;
	cout << "Linear search: ";
	cout << linear_search<T>(arr, n, key) << endl;
	cout << "B)" << endl;
	cout << "Sorted array: " << endl;
	cocktail_sort(arr, n);
	out_arr(arr, n);
	cout << "Binary search: ";
	cout << binary_search<T>(arr, n, key) << endl;
	cout << "Fibonacci search: ";
	cout << fibonacci_search<T>(arr, n, key) << endl;
	cout << "Interpolation search: ";
	cout << interpolation_search<T>(arr, n, key) << endl;
}