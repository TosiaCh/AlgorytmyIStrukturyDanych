// doublelist.h

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

using namespace std;

template <typename T>
struct DoubleNode {
// the default access mode and default inheritance mode are public
    T value;
    DoubleNode *next, *prev;
    // konstruktor domyslny (niepotrzebny)
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {} // konstruktor
    ~DoubleNode() { next = prev = nullptr;
} // destruktor
};


template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList(){
        while(head!=nullptr){
            DoubleNode<T> *node=head;
            head=head->next;
            delete node;
        }
        tail=nullptr;
    } // tu trzeba wyczyscic wezly

    DoubleList(const DoubleList& other){
        head=nullptr;
        tail=nullptr;
        if(other.head!=nullptr){
        DoubleNode<T> *otherList=other.head;
        
        while(otherList!=nullptr){
            DoubleNode<T> *node= new DoubleNode<T>(otherList->value);
            if(head==nullptr){
                head=node;
                tail=node;
            } else {
                tail->next=node;
                node->prev=tail;
                tail=node;
            }
            otherList=otherList->next;
        }
        }

    } // copy constructor
    // usage:   DoubleList<int> list2(list1);

   // DoubleList(DoubleList&& other); // move constructor NIEOBOWIAZKOWE
    // usage:   DoubleList<int> list2(std::move(list1));

    DoubleList& operator=(const DoubleList& other){
          if(this==&other){
            return *this;
        }

        while(head!=nullptr){
            DoubleNode<T> *temp=head;
            head=head->next;
            delete temp;
        }
        tail=nullptr;

        if(other.head!=nullptr){
        DoubleNode<T> *otherList=other.head;
        while(otherList!=nullptr){
            DoubleNode<T> *node= new DoubleNode<T>(otherList->value);
            if(head==nullptr){
                head=node;
                tail=node;
            } else {
                tail->next=node;
                node->prev=tail;
                tail=node;
            }
            otherList=otherList->next;
        }
        }

    return *this;
    } // copy assignment operator, return *this
    // usage:   list2 = list1;

  //  DoubleList& operator=(DoubleList&& other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE

    bool empty() const { return head == nullptr; }
    int size() const{
        int i=0;
        DoubleNode<T> *temp=head;
        while(temp!=nullptr){
        temp=temp->next;
        i++;
        }
        return i;
    } // O(n) bo trzeba policzyc
    void push_front(const T& item){
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}// O(1)
  //  void push_front(T&& item); // O(1) NIEOBOWIAZKOWE
void push_back(const T& item) {
    if (!empty()) {
        tail->next = new DoubleNode<T>(item, nullptr, tail);
        tail = tail->next;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}


 // O(1)
   // void push_back(T&& item); // O(1) NIEOBOWIAZKOWE
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(){
        assert(!empty());
        DoubleNode<T> *node=head;
        if(head==tail){
            head=tail=nullptr;
        }else{
            head=head->next;
        }
        delete node;
    } // usuwa poczatek O(1)
    void pop_back(){
        assert(!empty());
        DoubleNode<T> *node=tail;
        if(head==tail){
            head=tail=nullptr;
        }else{
            tail=tail->prev;
            tail->next=nullptr;
        }
        delete node;
    } // usuwa koniec O(1)
    void clear(){
        if(head==nullptr){
            return;
        }else{
        while(head!=nullptr){
        DoubleNode<T> *temp=head;
        head=head->next;
        delete temp;
        }
    tail=nullptr;
        }
    } // czyszczenie listy z elementow O(n)
    void display(){
        DoubleNode<T> *temp=head;
        while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
        }
        cout<<endl;
    } // O(n)
    void display_reversed(){
        DoubleNode<T> *temp=tail;
        while(temp->prev!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->prev;
        }
        cout<<endl;
    } // O(n)

   /* // Operacje z indeksami. NIEOBOWIAZKOWE
    T& operator[](int pos); // podstawienie L[pos]=item, odczyt L[pos]
    const T& operator[](int pos) const; // dostep do obiektu const
    void erase(int pos);
    int index(const T& item); // jaki index na liscie (-1 gdy nie ma) O(n)
    void insert(int pos, const T& item); // inserts item before pos,
    void insert(int pos, T&& item); // inserts item before pos,
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec. */
};

/* template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_front(T&& item) {
    if (!empty()) {
        head = new DoubleNode<T>(std::move(item), head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(std::move(item));
    }
} */

#endif

// EOF