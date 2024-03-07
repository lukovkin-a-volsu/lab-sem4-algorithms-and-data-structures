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
    Student() : _group("unknown"), _fullname("unknown"), _scholarship(0)
    {
    }

    Student(string group) : _group(group), _fullname("unknown"), _scholarship(0)
    {
    }

    void set_scholarship(int n)
    {
        if (n < 0)
            n = 0;
        _scholarship = n;
    }

    void set_fullName(string s)
    {
        _fullname = s;
    }

    void set_group(string s)
    {
        _group = s;
    }

    string get_fullname()
    {
        return _fullname;
    }

    string get_group()
    {
        return _group;
    }

    int get_scholarship()
    {
        return _scholarship;
    }

    static Student *get_rand_student_array(size_t n)
    {
        Student *arr = new Student[n];
        std::uniform_real_distribution<double> dist(RND_MIN, RND_MAX);
        for (size_t i = 0; i < n; i++)
        {
            int val = (int)dist(generator);
            arr[i].set_scholarship(val);
            string fullname = get_rand_fullname();
            arr[i].set_fullName(fullname);
            string group = get_rand_group();
            arr[i].set_group(group);
        }
        return arr;
    }

    static string get_rand_fullname()
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

    static string get_rand_group()
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

    bool operator-(Student &other)
    {
        return _group.compare(other.get_group());
        // return (_fullname == other._fullname) && (_group == other._group) && (_scholarship == other._scholarship);
    }

    bool operator==(Student &other)
    {
        return _group.compare(other.get_group()) == 0;
        // return (_fullname == other._fullname) && (_group == other._group) && (_scholarship == other._scholarship);
    }

    bool operator>(Student &other)
    {
        // return _scholarship > other._scholarship;
        // return (_fullname.compare(other._fullname) > 0) && (_group.compare(other._group) > 0) && (_scholarship > other._scholarship);
        return _group.compare(other.get_group()) > 0;
    }

    bool operator<(Student &other)
    {
        // return _scholarship < other._scholarship;
        // return (_fullname.compare(other._fullname) < 0) && (_group.compare(other._group) < 0) && (_scholarship < other._scholarship);
        return _group.compare(other.get_group()) < 0;
    }

    friend ostream &operator<<(ostream &os, Student &student)
    {
        os << "Student. Fullname: " << student.get_fullname() << ", group: " << student.get_group() << " scholarship: " << student.get_scholarship() << " rub." <<  endl;
        return os;
    }
};

#endif // STUDENT_H