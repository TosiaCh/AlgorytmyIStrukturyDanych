// mydeque.h
#include <iostream>
#include <cassert>
template <typename T>
class MyDeque {
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
public:
    MyDeque(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[msize];
        assert( tab != nullptr );
    } // default constructor
    ~MyDeque() { delete [] tab; }
     MyDeque(const MyDeque& other) :msize(other.msize),head(other.head), tail(other.tail) {
        tab = new T[msize];
        assert(tab != nullptr);
        for(int i = 0;i < msize;i++){
            tab[i] = other.tab[i];
        }
    } // copy constructor
   // MyDeque(MyDeque&& other); // move constructor NIEOBOWIĄZKOWE
    MyDeque& operator=(const MyDeque& other){
    if (this == &other) {
        return *this;
    }
    delete[] tab;
    msize = other.msize;
    head = other.head;
    tail = other.tail;
    tab= new T[msize];
    assert(tab!=nullptr);
    for (int i = 0; i < msize; ++i) {
        tab[i] = other.tab[i];
    }

    return *this;
} // copy assignment operator, return *this
  //  MyDeque& operator=(MyDeque&& other); // move assignment operator, return *this NIEOBOWIĄZKOWE
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    void push_front(const T& item){
    head = (head - 1 + msize) % msize;
    tab[head] = item;
    }// dodanie na początek O(1)
   // void push_front(T&& item); // dodanie na początek O(1) NIEOBOWIĄZKOWE
    void push_back(const T& item){
    tab[tail] = item;
    tail = (tail + 1) % msize;
    }// dodanie na koniec O(1)
   // void push_back(T&& item); // dodanie na koniec O(1) NIEOBOWIĄZKOWE
    T& front() { return tab[head]; } // zwraca poczatek
    T& back() { return tab[(tail - 1 + msize) % msize]; } // zwraca koniec
    void pop_front(){
        if(empty()){
            std::cout<<"error";
        }
        else{
            head = (head + 1) % msize;
        }
        
    } // usuwa początek kolejki O(1)
    void pop_back(){
        if(empty()){
            std::cout<<"error";
            return;
        }
        else{
            tail = (tail - 1 + msize) % msize;
        }
        
    } // usuwa koniec kolejki O(1)
    void clear(){
        tail = 0;
        head = 0;
    } // czyszczenie listy z elementów
    void display(){
    for (int i = head; i != tail; i = (i + 1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

    // Operacje z indeksami. NIEOBOWIĄZKOWE
  /*  T& operator[](int pos); // podstawienie L[pos]=item, odczyt L[pos]
    const T& operator[](int pos) const; // dostęp do obiektu const
    void erase(int pos);
    int index(const T& item); // jaki index na liście (-1 gdy nie ma)
    void insert(int pos, const T& item); // inserts item before pos
    void insert(int pos, T&& item); // inserts item before pos */
};