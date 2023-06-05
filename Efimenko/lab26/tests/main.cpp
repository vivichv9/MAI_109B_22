#include <iostream>
#include "../include/Deque.hpp"

void procedure(Deque<int>::Iterator& it, bool& flag, Deque<int>& deque) {
    auto temp_iter = deque.begin();
    while (temp_iter != it) {
        if (*it < *temp_iter) {
            deque.insert(temp_iter, *it);
            auto it_copy = it;
            flag = true;
            ++it;
            deque.erase(it_copy);
            break;
        }
        ++temp_iter;
    }
}

void insert(Deque<int>& deque) { 
    auto it = deque.begin();
    bool flag = false;
    ++it;
    for (; it != deque.end();) {
        flag = false;

        procedure(it, flag, deque);

        if (!flag) {
            ++it;
        }
    }
} 

int main() {
    Deque<int> deque = {123, 23, 454, 654, 32, 42, 1, 5, 8};

    insert(deque);

    auto ite = deque.begin();
    while (ite != deque.end()) {
        std::cout << *ite << ' '; 
        ++ite;
    }
}