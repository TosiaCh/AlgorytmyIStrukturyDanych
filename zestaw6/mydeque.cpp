#include <iostream>
#include <cassert>
#include "mydeque.h"

int main() {
    // Testowanie konstruktora domyślnego
    MyDeque<int> deque1;
    assert(deque1.size() == 0);
    assert(deque1.empty());

    // Testowanie dodawania elementów do deque1
    for (int i = 1; i <= 5; ++i) {
        deque1.push_back(i * 10);
    }
    deque1.display();
    assert(deque1.size() == 5);

    // Testowanie konstruktora kopiującego
    MyDeque<int> deque2(deque1);
    assert(deque2.size() == 5);

    // Testowanie operatora przypisania
    MyDeque<int> deque3;
    deque3 = deque1;
    assert(deque3.size() == 5);

    // Testowanie dodawania elementów na początek deque2
    for (int i = 1; i <= 3; ++i) {
        deque2.push_front(i * 5);
    }
    assert(deque2.size() == 8);

    // Testowanie usuwania elementów z końca deque1
    deque1.pop_back();
    assert(deque1.size() == 4);

    // Testowanie usuwania elementów z początku deque3
    deque3.pop_front();
    assert(deque3.size() == 4);

    // Testowanie czyszczenia deque2
    deque2.clear();
    assert(deque2.empty());

    std::cout << "Testy zaliczone!" << std::endl;

    return 0;
}