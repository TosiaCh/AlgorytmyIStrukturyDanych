
#include <iostream>
#include <cassert>
#include "arraylist.h"


int main(){

ArrayList<int> lista;

assert(lista.empty());


lista.push_front(1);
lista.push_front(2);
lista.push_back(3);

assert(lista.size()==3);
assert(lista.front()==2);
assert(lista.back()==3);

lista.pop_front();
lista.pop_back();

assert(lista.size()==1);

lista.push_front(5);
lista.push_back(8);
lista.push_back(2);

lista.reverse();

assert(lista.front()==2);
assert(lista.back()==5);

lista.sort();

assert(lista.front()==1);
assert(lista.back()==8);

lista.display();

lista.clear();
assert(lista.size()==0);



}