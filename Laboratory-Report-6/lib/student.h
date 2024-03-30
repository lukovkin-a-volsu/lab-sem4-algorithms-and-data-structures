#ifndef STUDENT_H
#define STUDENT_H

#include <ostream>
#include <string>

#include "urandom.h"

using std::cout;
using std::endl;
using std::getline;
using std::istream;
using std::ostream;
using std::string;
using std::to_string;

class Student {
 private:
  double scholarship_;
  string fullname_;
  string group_;
  static inline int order_{};

 public:
  Student() : group_("unknown"), fullname_("unknown"), scholarship_(0) {}

  Student(string group)
      : group_(group), fullname_("unknown"), scholarship_(0) {}

  void set_scholarship(double n) {
    if (n < 0) n = 0;
    scholarship_ = n;
  }

  void set_fullName(string s) { fullname_ = s; }

  void set_group(string s) { group_ = s; }

  string get_fullname() const { return fullname_; }

  string get_group() const { return group_; }

  double get_scholarship() const { return scholarship_; }

  Student &operator=(const Student &other) {
    if (this == &other) return *this;
    fullname_ = other.get_fullname();
    group_ = other.get_group();
    scholarship_ = other.get_scholarship();
    return *this;
  }

  Student &operator+=(const Student &other) {
    scholarship_ += other.get_scholarship();
    return *this;
  }

  bool operator-(const Student &other) const {
    return scholarship_ - other.get_scholarship();
  }

  Student &operator/(const Student &other) {
    scholarship_ /= other.get_scholarship();
    return *this;
  }

  bool operator==(const Student &other) const {
    const double eps = 1;
    return (abs(scholarship_ - other.get_scholarship()) < eps) &&
           (fullname_ == other.get_fullname()) && (group_ == other.get_group());
  }

  bool operator>(const Student &other) const {
    return scholarship_ > other.get_scholarship();
  }

  bool operator<(const Student &other) const {
    return scholarship_ < other.get_scholarship();
  }

  friend double operator+(double &d, Student &student) {
    return d += student.get_scholarship();
  }

  friend ostream &operator<<(ostream &os, const Student &student) {
    os << "Student. Fullname: " << student.get_fullname()
       << ", Group: " << student.get_group()
       << ", Scholarship: " << student.get_scholarship() << " rub." << endl;
    return os;
  }

  friend istream &operator>>(istream &is, Student &student) {
    cout << "Input fullname: ";
    getline(is, student.fullname_);
    cout << "Input group: ";
    getline(is, student.group_);
    cout << "Input scholarship: ";
    is >> student.scholarship_;
    return is;
  }

  static Student *RandStudentArr(size_t n) {
    Student *arr = new Student[n];
    std::uniform_real_distribution<double> dist(RND_MIN, RND_MAX);
    for (size_t i = 0; i < n; i++) {
      arr[i] = RandStudent();
    }
    return arr;
  }

  static Student &RandStudent(double min = 10, double max = 10000) {
    Student *stud = new Student();
    std::uniform_real_distribution<double> dist(min, max);
    double val = (double)dist(generator);
    stud->set_scholarship(val);
    string fullname = RandFullname();
    stud->set_fullName(fullname);
    string group = RandGroup();
    stud->set_group(group);
    return *stud;
  }

  static string RandFullname() {
    string names[] = {
        "Delaney Bennett",  "Hamza Proctor",    "Krista Calderon",
        "Bailey Watson",    "Gabriela Love",    "Yoselin Maynard",
        "Brenna Macdonald", "Yasmin Holloway",  "Johanna Pitts",
        "Kamron Lutz",      "Alejandro Mathis", "Yuliana Mckay",
        "Arjun Woods",      "Nico Collins",     "Kara Irwin",
        "Janae Ingram",     "Tyrell Nunez",     "Baylee Duarte",
        "Alberto Copeland", "Draven Lopez",
    };
    std::uniform_real_distribution<double> dist(0, 20);
    int idx = (int)dist(generator);
    string suffix = to_string(++order_);
    return names[idx] + suffix;
  }

  static string RandGroup() {
    string groups[] = {
        "PRIB-236", "PRIB-235", "PRIB-234", "PRIB-233", "PRIB-232",
        "PRIB-231", "PRIB-222", "PRIB-221", "ISTB-221", "IVTB-221",
    };
    std::uniform_real_distribution<double> dist(0, 10);
    int idx = (int)dist(generator);
    return groups[idx];
  }
};

#endif  // STUDENT_H