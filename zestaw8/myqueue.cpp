#include <iostream>
#include <cassert>
#include "myqueue.h"

int main(){
    MyQueue<int> lista;
    lista.push(1);
    lista.push(2);
    lista.push(3);
    lista.push(4);
    lista.push(5);
    lista.push(6);
    lista.push(7);
    lista.push(8);
    lista.push(9);
    lista.push(10);
    lista.pop();
    lista.push(7);

    lista.display();
    assert(lista.full());
    lista.clear();
    assert(lista.empty());

    lista.push(1);
    lista.push(2);
    lista.push(3);

    assert(!lista.empty());

    assert(lista.size() == 3);
    assert(lista.max_size() == 10);


    assert(lista.front() == 1);
    assert(lista.back() == 3);

    
    lista.pop();

    assert(lista.size() == 2);

    lista.display();

    MyQueue<int> lista2(lista);

    assert(lista.size() == lista2.size());
    assert(lista.front() == lista2.front());
    assert(lista.back() == lista2.back());

    MyQueue<int> lista3;
    lista3 = lista;

    assert(lista.size() == lista3.size());
    assert(lista.front() == lista3.front());
    assert(lista.back() == lista3.back());



    std::cout << "Testy zdane!" << std::endl;

    return 0;
}