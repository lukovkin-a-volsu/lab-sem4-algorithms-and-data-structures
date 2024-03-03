#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <ostream>
#include "urandom.h"

using std::endl;
using std::ostream;
using std::string;

class Student
{
private:
  int _scholarship;
  string _fullname;
  string _group;

public:
  Student();
  void setScholarship(int);
  void setFullName(string);
  void setGroup(string);
  string getFullname();
  string getGroup();
  int getScholarship();
  static Student *getRandomStudentArray(size_t);
  static string getRandomFullname();
  static string getRandomGroup();
  bool operator==(Student &);
  bool operator>(Student &);
  bool operator<(Student &);
  friend ostream &operator<<(ostream &, Student &);
};

#include "student.cpp"

#endif // STUDENT_H