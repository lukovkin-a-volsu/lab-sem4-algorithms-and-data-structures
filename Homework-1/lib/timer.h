#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include "hashtable.h"

using std::ofstream;
using std::size_t;
using std::string;
using std::cout;
using std::endl;

class Timer {
  size_t min_, max_, n_, times_;
  string add_fname_, rem_fname_;

 public:
  Timer()
      : min_{0},
        max_{10},
        n_{4096},
        times_{100},
        add_fname_{"add.txt"},
        rem_fname_{"rem.txt"} {}

  void Test() {
    HashTable<int, int> ht;

    ofstream out1(add_fname_);
    for (int i = 0; i < n_; i++) {
      double avg = 0;
      double total_duration = 0;
      // loop to calculate adding one element several times
      for (int j = 0; j < times_; j++) {
        ht.Rem(i);
        auto start_time = std::chrono::high_resolution_clock::now();
        ht.Add(i, i);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
                            end_time - start_time)
                            .count();
        total_duration += duration;
      }
      // avg = total_duration / (times_ * 1e6); // in ms
      avg = total_duration / times_; // in ns
      out1 << i + 1 << ";" << avg << endl;
    }
    out1.close();

    // copypaste for removing :)
    ofstream out2(rem_fname_);
    for (int i = 0; i < n_; i++) {
      double avg = 0;
      double total_duration = 0;
      for (int j = 0; j < times_; j++) {
        auto start_time = std::chrono::high_resolution_clock::now();
        ht.Rem(i);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
                            end_time - start_time)
                            .count();
        total_duration += duration;
      }
      // avg = total_duration / (times_ * 1e6); // in ms
      avg = total_duration / times_; // in ns
      out2 << i + 1 << ";" << avg << endl;
    }
    out2.close();
  }
};

#endif  // TIMER_H