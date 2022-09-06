#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>

void QuickSort(std::vector<int>& in, int begin, int end);

int PartQuickSortCore(std::vector<int>& in, int begin, int end);
void PartQuickSort(std::vector<int>& in, int k);
int BigK(std::vector<int>& in, int k);

#endif