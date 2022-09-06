#include "Util.h"
#include "../include/BubbleSort.h"
#include "../include/QuickSort.h"

#include <iostream>
#include <vector>

int main(int argc, char **argv) {
    std::vector<int> in = {9,8,7,6,5,4,3,2,1};
    std::cout << in;
    std::cout << BigK(in, 6) << std::endl;
    return 0;
}