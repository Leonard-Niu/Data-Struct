#include "../include/QuickSort.h"

void QuickSort(std::vector<int>& in, int begin, int end) {
    if (begin >= end) {
        return;
    }

    int left = begin;
    int right = end;
    int tmp = in[left];
    while (left < right) {
        while (left < right && in[right] > tmp) {
            --right;
        }
        if (left < right) {
            in[left] = in[right];
            ++left;
        }
        while (left < right && in[left] < tmp) {
            ++left;
        }
        if (left < right) {
            in[right] = in[left];
            --right;
        }
    }
    in[left] = tmp;
    QuickSort(in, begin, left - 1);
    QuickSort(in, left + 1, end);
}

int PartQuickSortCore(std::vector<int>& in, int begin, int end) {
    if (begin >= end) {
        return begin;
    }

    int left = begin;
    int right = end;
    int tmp = in[left];
    while (left < right) {
        while (left < right && in[right] > tmp) {
            --right;
        }
        if (left < right) {
            in[left] = in[right];
            ++left;
        }
        while (left < right && in[left] < tmp) {
            ++left;
        }
        if (left < right) {
            in[right] = in[left];
            --right;
        }
    }
    in[left] = tmp;
    return left;
}

void PartQuickSort(std::vector<int>& in, int k) {
    if (k > in.size()) {
        return QuickSort(in, 0, in.size() - 1);
    }

    int left = 0;
    int right = in.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int tmpIndex = PartQuickSortCore(in, left, right);

        if (tmpIndex == in.size() - 1 - k + 1) {
            break;
        } else if (tmpIndex < in.size() - 1 - k + 1) {
            left = tmpIndex + 1;
        } else {
            right = tmpIndex - 1;
        }
    }
}

int BigK(std::vector<int>& in, int k) {
    if (k > in.size()) {
        return BigK(in, in.size() - 1);
    }

    int left = 0;
    int right = in.size() - 1;
    int tmpIndex = left;
    while (left < right) {
        int mid = left + (right - left) / 2;
        tmpIndex = PartQuickSortCore(in, left, right);

        if (tmpIndex == in.size() - 1 - k + 1) { // current kth big index(+1 means start from 1, not from 0)
            break;
        } else if (tmpIndex < in.size() - 1 - k + 1) {
            left = tmpIndex + 1;
        } else {
            right = tmpIndex - 1;
        }
    }
    return in[tmpIndex];
}