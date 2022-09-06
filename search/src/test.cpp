#include "../include/Search.h"

int main(int argc, char **argv) {
    --argc;
    ++argv;

    std::vector<int> input = {4,4,5,1,2,3,4};
    int target = 0;
    if (argc == 1) {
        target = atoi(argv[0]);
    }
    std::cout << RotateSearch(input) << std::endl;
    return 0;
}