#include "../include/BubbleSort.h"

void BubbleSort(std::vector<int>& input) {
    for (int outer = 0; outer < input.size() - 1; ++outer) {
        bool swapFlag = false;
        for (int inner = 0; inner < input.size() - outer - 1; ++inner) {
            if (input[inner] > input[inner + 1]) {
                std::swap(input[inner], input[inner + 1]);
                swapFlag = true;
            }
        }
        if (!swapFlag) { // early break
            std::cout << "early break" << std::endl;
            break;
        }
    }
}