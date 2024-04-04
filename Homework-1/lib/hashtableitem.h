#ifndef HASHTABLEITEM_H
#define HASHTABLEITEM_H

template <class K, class V>
class HashTableItem {
 public:
  K key_;
  V value_;
  HashTableItem *next_{nullptr};

  HashTableItem(K key, V value) : key_{key}, value_{value} {}
};

#endif  // HASHTABLEITEM_H
