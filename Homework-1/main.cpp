#include <iostream>

#include "lib/hashtable.h"

using std::cout;
using std::endl;

int main() {
  HashTable<int, int> table;

  for (int i = 0; i < 135; i++) {
    table.Add(i, 2 * i - i % 6);
    // cout << "New item: " << i + 1 << " " << 2 * i - i % 6 << endl;
  }
  return 0;
}