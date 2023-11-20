#include <iostream>
#include <list>

std::list<int> rotateList(std::list<int>& list, int k) {
    while (k > 0) {
        int tmp = list.back();
        list.pop_back();
        list.push_front(tmp);
        k--;
    }

    return list;
}

void printList(std::list<int>& list) {
    for (int element : list) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> list = {0, 1, 2};
    std::list<int> result = rotateList(list, 4);
    printList(result);
    return 0;
}