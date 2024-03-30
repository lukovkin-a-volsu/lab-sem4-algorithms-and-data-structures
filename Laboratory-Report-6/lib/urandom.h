#ifndef URANDOM_H
#define URANDOM_H

#include <chrono>
#include <random>

#ifndef RND_MIN
#define RND_MIN -10000
#endif
#ifndef RND_MAX
#define RND_MAX 10000
#endif

std::default_random_engine generator(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());

#endif  // URANDOM_H
