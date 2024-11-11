#include "doublelist.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(){

    DoubleList<int> myList;

    myList.push_front(3);
    myList.push_front(2);
    myList.push_front(1);
    myList.push_back(4);
    myList.push_back(5);

    assert(myList.size() == 5);

    assert(myList.front() == 1);
    assert(myList.back() == 5);

    cout << "Original List: ";
    myList.display();  // output: 1 2 3 4 5

    myList.pop_front();
    cout << "After pop_front: ";
       myList.display(); // output: 2 3 4 5
    assert(myList.size() == 4);
    assert(myList.front() == 2);

    myList.pop_back();
    cout<<"After pop_back: ";
        myList.display();// output: 2 3 4
    assert(myList.size() == 3);
    assert(myList.back() == 4);

    cout << "Reversed List: ";
    myList.display_reversed();

     // output: 4 3 2

    myList.clear();
    assert(myList.size() == 0);
    assert(myList.empty());
    cout<<"Tests passed"<<endl;

    return 0;
}