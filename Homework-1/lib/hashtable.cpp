#include "hashtable.h"

// debugging
using std::cout;
using std::endl;

template <class K, class V>
HashTable<K, V>::HashTable() : size_(CAPACITY), count_(0) {
  table_ = new Item<K, V>*[CAPACITY];
  for (size_t i = 0; i < CAPACITY; i++) {
    table_[i] = nullptr;
  }
}

template <class K, class V>
HashTable<K, V>::HashTable(size_t capacity) : size_(capacity), count_(0) {
  table_ = new Item<K, V>*[capacity];
  for (size_t i = 0; i < capacity; i++) {
    table_[i] = nullptr;
  }
}

template <class K, class V>
HashTable<K, V>::~HashTable() {
  for (size_t i = 0; i < size_; i++) {
    if (table_[i] != nullptr) {
      delete table_[i];
    }
  }
  delete[] table_;
  size_ = 0;
  count_ = 0;
}

template <class K, class V>
hcode HashTable<K, V>::HashCode(const K& key) const {
  // if (is_class<V>::key) {
  //   // T is a class instance
  //   cout << "Class instance " << endl;
  //   return key.HashCode();
  // } else {
  //   // T is a primitive data type
  //   cout << "Primitive type " << endl;
  //   return std::hash<K>{}(key);
  // }
  hcode res;

  if (typeid(K) == typeid(int)) {
    // SumDigits
    {
      int sum = 0;
      K number(key);
      while (number != 0) {
        sum += number % 10;
        number /= 10;
      }
      res = sum % size_;
    }
  } else {
    throw runtime_error("Unsupported type");
  }

  return res;
}

template <class K, class V>
size_t HashTable<K, V>::get_size() {
  return size_;
}

template <class K, class V>
void HashTable<K, V>::Rehashing() {
  size_t new_size = size_ * 2;
  size_t new_count = count_;
  HashTable<K, V>* new_htable = new HashTable(new_size);
  // copy elements
  for (size_t i = 0; i < size_; i++) {
    if (table_[i] != nullptr) {
      Item<K, V>* cur = table_[i];
      do {
        new_htable->Add(cur->key_, cur->value_);
        cur = cur->next_;
      } while (cur != nullptr);
    }
  }

  // clear old table
  for (size_t i = 0; i < size_; i++) {
    if (table_[i] != nullptr) {
      delete table_[i];
    }
  }

  // cout << "Table size increased from " << size_ << " to " << new_size <<
  // endl;

  // update vars
  table_ = new_htable->table_;
  size_ = new_size;
  count_ = new_count;
}

template <class K, class V>
void HashTable<K, V>::HandleCollision(Item<K, V>*& new_item) {
  // handling using linked list
  Item<K, V>* current = table_[new_item->key];
  while (current.next != nullptr) {
    current = current->next;
  }
  current->next = new_item;
}

template <class K, class V>
void HashTable<K, V>::Add(const K& key, const V& value) {
  // Steps:
  //  1. Calculate hash code
  //  2. If performed hash code was occupied - move to 4
  //  3. Place item
  //  4. Escape from collision

  // Rehashing before performing hashcode
  // count_ always return number of last element
  if (count_ >= size_) {
    Rehashing();
  }
  hcode index = HashCode(key);
  Item<K, V>* new_item = new Item(key, value);
  // cout << "Hashcode: " << index << endl;
  if (table_[index] == nullptr) {
    table_[index] = new_item;
  } else {
    // collision
    Item<K, V>* tmp = table_[index];
    while (tmp->next_ != nullptr) {
      tmp = tmp->next_;
    }
    tmp->next_ = new_item;
  }
  count_++;
}

template <class K, class V>
Item<K, V>* HashTable<K, V>::Get(K key) {
  hcode index = HashCode(key);
  // if hash not in table return nullptr
  if (table_[index] == nullptr) return nullptr;
  Item<K, V>* cur = table_[index];
  // linked list searching item
  do {
    if (cur->key_ == key) return cur;
    cur = cur->next_;
  } while (cur != nullptr);
  // item not found
  return nullptr;
}

template <class K, class V>
bool HashTable<K, V>::Rem(K key) {
  hcode index = HashCode(key);
  if (table_[index] == nullptr) return false;
  // if element is a head
  if (table_[index]->key_ == key) {
    if (table_[index]->next_ == nullptr) {
      delete table_[index];
      table_[index] = nullptr;
    } else {
      Item<K, V>* new_head = table_[index]->next_;
      delete table_[index];
      table_[index] = new_head;
    }
    count_--;
    return true;
  }
  Item<K, V>* prev = nullptr;
  Item<K, V>* cur = table_[index];
  // linked list searching
  do {
    if (cur->key_ == key) {
      prev->next_ = cur->next_;
      delete cur;
      count_--;
      return true;
    }
    prev = cur;
    cur = cur->next_;
  } while (cur != nullptr);
  return false;
}