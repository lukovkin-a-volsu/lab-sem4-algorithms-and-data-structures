#include "student.h"

Student::Student() : _group("unknown"), _fullname("unknown"), _scholarship(0)
{
}

void Student::setScholarship(int n)
{
  if (n < 0)
    n = 0;
  _scholarship = n;
}

void Student::setFullName(string s)
{
  _fullname = s;
}

void Student::setGroup(string s)
{
  _group = s;
}

string Student::getFullname()
{
  return _fullname;
}

string Student::getGroup()
{
  return _group;
}

int Student::getScholarship()
{
  return _scholarship;
}

Student *Student::getRandomStudentArray(size_t n)
{
  Student *arr = new Student[n];
  std::uniform_real_distribution<double> dist(RND_MIN, RND_MAX);
  for (size_t i = 0; i < n; i++)
  {
    int val = (int)dist(generator);
    arr[i].setScholarship(val);
    string fullname = getRandomFullname();
    arr[i].setFullName(fullname);
    string group = getRandomGroup();
    arr[i].setGroup(group);
  }
  return arr;
}

string Student::getRandomFullname()
{
  string names[] = {
      "Delaney Bennett",
      "Hamza Proctor",
      "Krista Calderon",
      "Bailey Watson",
      "Gabriela Love",
      "Yoselin Maynard",
      "Brenna Macdonald",
      "Yasmin Holloway",
      "Johanna Pitts",
      "Kamron Lutz",
      "Alejandro Mathis",
      "Yuliana Mckay",
      "Arjun Woods",
      "Nico Collins",
      "Kara Irwin",
      "Janae Ingram",
      "Tyrell Nunez",
      "Baylee Duarte",
      "Alberto Copeland",
      "Draven Lopez",
  };
  std::uniform_real_distribution<double> dist(0, 20);
  int idx = (int)dist(generator);
  return names[idx];
}

string Student::getRandomGroup()
{
  string groups[] = {
      "PRIB-236",
      "PRIB-235",
      "PRIB-234",
      "PRIB-233",
      "PRIB-232",
      "PRIB-231",
      "PRIB-222",
      "PRIB-221",
      "ISTB-221",
      "IVTB-221",
  };
  std::uniform_real_distribution<double> dist(0, 10);
  int idx = (int)dist(generator);
  return groups[idx];
}

bool Student::operator==(Student &other)
{
  return (_fullname == other._fullname) && (_group == other._group) && (_scholarship == other._scholarship);
}

bool Student::operator>(Student &other)
{
  // return _scholarship > other._scholarship;
  // return (_fullname.compare(other._fullname) > 0) && (_group.compare(other._group) > 0) && (_scholarship > other._scholarship);
  return _group.compare(other.getGroup()) > 0;
}

bool Student::operator<(Student &other)
{
  // return _scholarship < other._scholarship;
  // return (_fullname.compare(other._fullname) < 0) && (_group.compare(other._group) < 0) && (_scholarship < other._scholarship);
  return _group.compare(other.getGroup()) < 0;
}

ostream &operator<<(ostream &os, Student &student)
{
  os << "Student. Fullname: " << student.getFullname() << ", group: " << student.getGroup() << " scholarship:" << student.getScholarship() << " rub." << endl;
  return os;
}