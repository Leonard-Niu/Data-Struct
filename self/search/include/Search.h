#ifndef SEARCH_H
#define SEARCH_H


#include <iostream>
#include <vector>

bool BinSearch(std::vector<int>& input, int target);
int LeftSearch(std::vector<int>& input, int target);
int RightSearch(std::vector<int>& input, int target);
int SameCount(std::vector<int>& input, int target);
// bad naming!
int RotateSearch(std::vector<int>& input);

#endif