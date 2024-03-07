#ifndef ALIAS_H
#define ALIAS_H

#include <iostream>
#include <functional>

using std::function;
using std::string;

// using search_function = function<int(const string *, size_t, const string &)>;
using lambda = function<void()> &;

template<class T>
using search_function = std::function<int(T*, size_t, T)>;

// template <class T>
// using SearchFunction = std::function<int(T *, size_t, T)>;


#endif //ALIAS_H