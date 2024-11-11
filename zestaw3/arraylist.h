// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
class ArrayList {
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja
public:
    ArrayList(int s=10) : msize(s), last(0) {
        assert( s > 0 );
        tab = new T[s];
        assert( tab != nullptr ); } // default constructor

    ~ArrayList() { 
        delete [] tab; } // destruktor

    ArrayList(const ArrayList& other): msize(other.s), last(other.last) {
        tab = new T[other.msize];
        assert( tab != nullptr ); 
        for(int i=0;i<last;i++){
            tab[i]=other.tabl[i];
         }
    } // copy constructor
    // usage:   ArrayList<int> list2(list1);

  //  ArrayList(ArrayList&& other); // move constructor NIEOBOWIAZKOWE
    // usage:   ArrayList<int> list2(std::move(list1));

    ArrayList& operator=(const ArrayList& other){
        if(this==&other){
            return *this;
        }}// copy assignment operator, return *this
    // usage:   list2 = list1;

   // ArrayList& operator=(ArrayList&& other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE

    bool empty() const { 
        return last == 0; 
        } // checks if the container has no elements

    bool full() const { 
        return last == msize; 
        } // checks if the container is full

    int size() const { 
        return last;
         } // liczba elementow na liscie

    int max_size() const {
         return msize; 
         } // najwieksza mozliwa liczba elementow

    void push_front(const T& item){
      if(last<msize){
        for(int i=last;i>0;i--){
            tab[i]=tab[i-1];
        }
    tab[0]=item;
    last++;
    } else{
        throw std::runtime_error("List is full");
    }
    } // dodanie na poczatek

    // void push_front(T&& item); // dodanie na poczatek NIEOBOWIAZKOWE

    void push_back(const T& item){
        if(last<msize){
            tab[last]=item;
            last++;
        } else {
            throw std::runtime_error("List is full");
        }
        
    } // dodanie na koniec

    // void push_back(T&& item);// dodanie na koniec NIEOBOWIAZKOWE

    T& front(){
        if(last==0){
            throw std::runtime_error("List is empty");
        }
        else{
        return tab[0];}} // zwraca poczatek, nie usuwa, error dla pustej listy

    T& back(){
         if(last==0){
            throw std::runtime_error("List is empty");
        }
        else{
        return tab[last-1];}} // zwraca koniec, nie usuwa, error dla pustej listy

    void pop_front(){
         if(last==0){
            throw std::runtime_error("List is empty");
        }
        else{
            for(int i=0;i<last;i++){
                tab[i]=tab[i+1];
            }
            last --;

    }
    } // usuwa poczatek, error dla pustej listy

    void pop_back(){
         if(last==0){
            throw std::runtime_error("List is empty");
        }
        else{
            last=last-1; }} // usuwa koniec, error dla pustej listy

    void clear(){
        last=0;} // czyszczenie listy z elementow

    void display(){
    for (int i = 0; i < last; ++i) {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    } // lepiej zdefiniowac operator<<

    void reverse(){
        T* arr= new T[last];
        for(int i=0;i<last;i++){
            arr[i]=tab[i];
        }
        int j=0;
        for(int i=last-1;i>=0;i--){
            tab[i]=arr[j];
            j++;
        }
        delete [] arr;}// odwracanie kolejnosci

    void sort(){
          for (int i = 0; i < last - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < last - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                std::swap(tab[j], tab[j + 1]);
                swapped = true;}}
        if (!swapped) {
            break;}}} // sortowanie listy

 //   void merge(ArrayList& other); //  merges two sorted lists into one NIEOBOWIAZKOWE
/*
    // Operacje z indeksami. NIEOBOWIAZKOWE
    // https://en.cppreference.com/w/cpp/language/operators
    // Array subscript operator
    T& operator[](int pos); // podstawienie L[pos]=item, odczyt L[pos]
    const T& operator[](int pos) const; // dostep do obiektu const
    void erase(int pos); // usuniecie elementu na pozycji pos
    int index(const T& item); // jaki index na liscie (-1 gdy nie ma)
    void insert(int pos, const T& item); // inserts item before pos
    void insert(int pos, T&& item); // inserts item before pos
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.
    */

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) { // odwolanie L.last
            os << L.tab[i] << " ";   // odwolanie L.tab
        }
        return os;
    } // usage:   std::cout << L << std::endl;
};

#endif

// EOF