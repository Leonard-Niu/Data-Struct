#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& cout, std::vector<int> in);

// how to apply template with another template?
template<typename T>
void print(std::vector<T> in);

#endif