#ifndef HASHTABLE_H
#define HASHTABLE_H

#ifndef CAPACITY
#define CAPACITY 128
#endif  // CAPACITY

#include <algorithm>
#include <iostream>
#include <type_traits>

#include "hashtableitem.h"

template <class K, class V>
using Item = HashTableItem<K, V>;
typedef unsigned long long hcode;

using std::is_class;
using std::runtime_error;
using std::size_t;

template <class K, class V>
class HashTable {
 private:
  size_t size_;
  size_t count_;
  // table with elements of type V or HashTable (when collision)
  Item<K, V>** table_;

  /**
   * Calculate hashcode for hashtable item
   * K key            New hashtable element
   * return           Hashcode for item
   */
  hcode HashCode(const K& key) const;

  /**
   * Reallocate memory for table and calculate hash for each item
   * Item*& new_item  New hashtable element
   * return           Void
   */
  void Rehashing();

  /**
   * Handle collision using linked list
   * Item*& new_item  New hashtable element
   * return           Void
   */
  void HandleCollision(Item<K, V>*& new_item);

 public:
  HashTable();
  HashTable(size_t capacity);
  ~HashTable();

  /**
   * Size getter
   * return           Capacity of hashtable
   */
  size_t get_size();

  /**
   * Add item to hashtable
   * K key            Key for new element
   * V element        New hashtable element
   * return           Void
   */
  void Add(const K& key, const V& value);

  /**
   * Add item to hashtable
   * K key            Key for new element
   * V element        New hashtable element
   * return           The value to which the specified key is mapped, or null if
   * element not found
   */
  Item<K, V>* Get(K key);

  /**
   * Remove item from hashtable
   * K item           Item that will be removed from hashtable
   * return           True when item was found
   */
  bool Rem(K key);
};

// Because template functions must be declared in the same file
#include "hashtable.cpp"

#endif