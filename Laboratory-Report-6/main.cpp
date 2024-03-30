#include <unistd.h>  // for sleep()

#include <algorithm>
#include <iostream>
#include <vector>

#include "lib/student.h"

using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::max_element;
using std::min_element;
using std::remove_if;
using std::replace_if;
using std::sort;
using std::transform;
using std::vector;

inline void Print(vector<Student>& g) {
  for (auto s : g) {
    cout << s;
  }
}

inline void RandFill(vector<Student>& g, size_t n) {
  for (size_t i = 0; i < n; i++) {
    Student student = Student::RandStudent();
    g.push_back(student);
    sleep(.10);
  }
}

inline bool CompareStudents(const Student& a, const Student& b) {
  return a < b;
}

int main() {
  size_t size;
  double avg;
  vector<Student> group;
  Student s;

  cout << "Input size of array: ";
  cin >> size;
  cin.get();

  cout << "Task 1." << endl;
  RandFill(group, size);
  Print(group);  // 1

  cout << "Task 2." << endl;
  avg = accumulate(group.begin(), group.end(), .0) / group.size();
  auto min_it = min_element(group.begin(), group.end(), CompareStudents);
  // cout << "Min: " << (*min_it);
  replace_if(
      group.begin(), group.end(),
      [avg](const Student& a) { return avg > a.get_scholarship(); }, (*min_it));
  Print(group);  // 2

  cout << "Task 3." << endl;
  for (int i = 0; i < 2; i++) {
    auto max_it = max_element(group.begin(), group.end(), CompareStudents);
    // cout << "Max: " << (*max_it);
    auto new_end =
        remove_if(group.begin(), group.end(),
                  [max_it](const Student& a) { return a == (*max_it); });
    group.erase(new_end, group.end());
  }
  Print(group);  // 3

  cout << "Task 4." << endl;
  sort(group.begin(), group.end(), CompareStudents);
  Print(group);  // 4

  cout << "Task 5." << endl;
  cin >> s;
  cin.get();
  auto find_it = find(group.begin(), group.end(), s);
  cout << "Found element: " << endl;
  if (find_it != group.end()) {
    cout << (*find_it);  // 5
  } else {
    cout << "Element not found." << endl;
  }

  cout << "Task 6." << endl;
  auto max_it = max_element(group.begin(), group.end(), CompareStudents);
  std::transform(group.begin(), group.end(), group.begin(),
                 [max_it](Student& a) { return a / (*max_it); });
  Print(group);

  return 0;
}