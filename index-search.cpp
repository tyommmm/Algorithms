#include <iostream>
#include <vector>

int ternary_search(const std::vector<int>& arr, int target, int start, int end) {
    if (start <= end) {
        int middenLeft = start + (end - start) / 3;
        int middenRight = start + 2 * (end - start) / 3;

        if (arr[middenLeft] == target) {
            return middenLeft;
        }
        if (arr[middenRight] == target) {
            return middenRight;
        }
        if (target < arr[middenLeft]) {
            return ternary_search(arr, target, start, middenLeft - 1);
        } 
        else if (target > arr[middenRight]) {
            return ternary_search(arr, target, middenRight + 1, end);
        } 
        else {
            return ternary_search(arr, target, middenLeft + 1, middenRight - 1);
        }
    }

    return -1;
}

std::pair<int, int> search_indexes(std::vector<int>& arr, int target) {
    int index = ternary_search(arr, target, 0, arr.size() - 1);
    if (index != -1) {
        int left = index;
        int right = index;
        while (arr[left] == target) {
            left--;
        }
        while (arr[right] == target) {
            right++;
        }

        return std::pair(left + 1, right - 1);
    }
    
    return std::pair(-1, -1);
}

int main() {
    std::vector<int> arr = {};
    std::pair<int, int> result = search_indexes(arr, 8);
    std::cout << "[" << result.first << ", " << result.second << "]\n";

    return 0;
}