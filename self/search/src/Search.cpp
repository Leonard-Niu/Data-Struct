#include "../include/Search.h"

bool BinSearch(std::vector<int>& input, int target) {
    int left = 0;
    int right = input.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (input[mid] == target) {
            return true;
        } else if (input[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (input[left] == target) {
        return true;
    } else {
        return false;
    }
}

int LeftSearch(std::vector<int>& input, int target) {
    int left = 0;
    int right = input.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (input[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (input[left] == target) {
        return left;
    } else {
        return -1;
    }
}

int RightSearch(std::vector<int>& input, int target) {
    int left = 0;
    int right = input.size() - 1;
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (input[mid] > target) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    if (input[left] == target) {
        return left;
    } else {
        return -1;
    }
}

int SameCount(std::vector<int>& input, int target) {
    int leftIndex = LeftSearch(input, target);
    int rightIndex = RightSearch(input, target);
    if (leftIndex != -1 && rightIndex != -1) {
        return rightIndex - leftIndex + 1;
    } else {
        return -1;
    }
}

int RotateSearch(std::vector<int>& input) {
    int left = 0;
    int right = input.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (input[mid] > input[right]) {
            left = mid + 1;
        } else if (input[mid] < input[right]) {
            right = mid;
        } else {
            --right;
        }
        std::cout << "left:" << left << " right:" << right << std::endl;
    }
    return input[left];
}