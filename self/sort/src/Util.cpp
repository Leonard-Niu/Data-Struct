#include "../include/Util.h"

std::ostream& operator<<(std::ostream& cout, std::vector<int> in) {
    for (int index = 0; index < in.size(); ++index) {
        if (index < in.size() - 1) {
            cout << in[index] << "|";
        } else {
            cout << in[index];
        }
    }
    cout << std::endl;
    return cout;
}

template<typename T>
void print(std::vector<T> in) {
    for (int index = 0; index < in.size(); ++index) {
        if (index < in.size() - 1) {
            std::cout << in[index] << "-";
        } else {
            std::cout << in[index];
        }
    }
    std::cout << std::endl;
}