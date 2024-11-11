#include <iostream>
#include <cassert>
#include "priorityqueue.h"

int main() {
    
    MyPriorityQueue<int> originalQueue;
    assert(originalQueue.empty());
    originalQueue.push(5);
    originalQueue.push(10);
    originalQueue.push(3);

    assert(originalQueue.top() == 10);
    assert(originalQueue.size() == 3);

    originalQueue.pop();

    assert(originalQueue.top() == 5);

    std::cout<<"To nasza kolejka: ";
    originalQueue.display();
    std::cout<<std::endl;

    MyPriorityQueue<int> copiedQueue(originalQueue);
    assert(copiedQueue.size() == originalQueue.size());
    assert(copiedQueue.top() == originalQueue.top());

    MyPriorityQueue<int> assignedQueue;
    assignedQueue = originalQueue;
    assert(assignedQueue.size() == originalQueue.size());
    assert(assignedQueue.top() == originalQueue.top());

    MyPriorityQueue<int> movedQueue(std::move(originalQueue));
    assert(originalQueue.size() == 0);
    assert(movedQueue.size() > 0);
    assert(movedQueue.top() == 5);

    MyPriorityQueue<int> anotherQueue;
    anotherQueue = std::move(movedQueue);
    assert(movedQueue.size() == 0);
    assert(anotherQueue.size() > 0);
    assert(anotherQueue.top() == 5);   

    std::cout <<"Testy zdane!\n";

    return 0;
}
