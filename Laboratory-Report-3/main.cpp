#include <fstream>
#include "lib/sort.h"
#include "lib/student.h"

using std::cin;
using std::ofstream;

bool menu();
template <class T>
void auto_test(ofstream &out);
template <class T>
void test(int times, size_t n, double &avg_ms);

int main()
{
	bool is_working;
	cout << "##### 1. 2." << endl;
	do
	{
		is_working = menu();
	} while (is_working);

	size_t n;
	double ms;
	cout << "##### 3." << endl;
	cout << "User data type test." << endl;
	cout << "Input array size:" << endl
		 << "> ";
	cin >> n;
	if (n > 0)
	{
		Student *students = Student::getRandomStudentArray(n);
		cout << "New array: " << endl;
		out_arr<Student>(students, n);
		// лексикографическом порядке группы
		cocktail_sort<Student>(students, n, ms);
		cout << "Sorted array: " << endl;
		out_arr<Student>(students, n);
		cout << ms << " ms." << endl;
	}

	cout << endl << "##### 4." << endl;
	ofstream file("output.txt");
	auto_test<int>(file);

	cout << endl << "##### 5." << endl;

	cout << "##### a)" << endl;
	size_t na = 50000;
	int *arr_a = new int[na];
	for (size_t i = 0; i < na; i++)
	{
		std::uniform_real_distribution<double> dist(0, 50000);
		int val = (int)dist(generator);
		arr_a[i] = 3;
	}
	// cout << "New array: " << endl;
	// out_arr<int>(arr, n2);
	cocktail_sort<int>(arr_a, na, ms);
	// cout << "Sorted array: " << endl;
	// out_arr<int>(arr, n2);
	cout << ms << " ms." << endl;

	cout << "##### b)" << endl;
	size_t nb = 50000;
	int *arr_b = new int[nb];
	for (size_t i = 0; i < nb; i++)
	{
		arr_b[i] = nb - i;
	}
	cocktail_sort<int>(arr_b, nb, ms);
	cout << ms << " ms." << endl;

	cout << "##### c)" << endl;
	size_t nc = 50000;
	int *arr_c = new int[nc];
	for (size_t i = 0; i < nc; i++)
	{
		arr_c[i] = nc;
	}
	cocktail_sort<int>(arr_c, nc, ms);
	cout << ms << " ms." << endl;

	return 0;
}

bool menu()
{
	size_t n;
	double ms;
	int *arr;

	cout << "Input array size (or <=0 to exit): " << endl
		 << "> ";
	cin >> n;

	if (n <= 0)
	{
		cout << endl
			 << "Exit" << endl
			 << endl;
		return false;
	}

	arr = rand_arr<int>(n);
	cout << "New array: " << endl;
	out_arr<int>(arr, n);
	cocktail_sort<int>(arr, n, ms);
	cout << endl
		 << "Sorted array: " << endl;
	out_arr<int>(arr, n);
	cout << endl
		 << ms << " ms." << endl;

	return true;
}

template <class T>
void auto_test(ofstream &out)
{
	double avg_ms;
	int times = 100;
	// int n_arr[]{1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};
	size_t n_arr[]{100, 500, 1000, 2000, 3000, 4000, 5000, 7500, 10000};

	for (size_t n : n_arr)
	{
		test<T>(times, n, avg_ms);
		cout << "N: " << n << "; T: " << avg_ms << " ms." << endl;
		out << n << ";" << avg_ms << endl;
	}
	cout << endl;
}

template <class T>
void test(int times, size_t n, double &avg_ms)
{
	avg_ms = 0;
	for (size_t i = 0; i < times; i++)
	{
		double ms = 0;
		T *arr = rand_arr<T>(n);
		cocktail_sort<T>(arr, n, ms);
		avg_ms += ms;
	}
	avg_ms /= times;
}