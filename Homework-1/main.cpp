#include <iostream>

#include "lib/hashtable.h"
#include "lib/timer.h"

using std::cout;
using std::endl;

int main() {
  HashTable<int, int> ht;
  ht.Add(3, 10);
  ht.Add(3, 16);
  ht.Add(21, 96);  // collision
  ht.Add(4, 11);
  cout << ht.Get(3)->value_ << endl;
  cout << ht.Get(21)->value_ << endl;

  ht.Rem(4);

  auto found = ht.Get(4);
  if (found != nullptr) {
    cout << found->value_;
  } else {
    cout << "Item doesn't exist" << endl;
  }
  
  // or testing:
  // Timer timer;
  // timer.Test();

  return 0;
}