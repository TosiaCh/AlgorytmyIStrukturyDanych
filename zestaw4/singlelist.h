// singlelist.h

#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>   // assert()
using namespace std;

//struktura SigleNode zmienna typu T value i pointer na kolejny SingleNode pointer nazywa się next;

template <typename T>
struct SingleNode {
// the default access mode and default inheritance mode are public
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} 
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    /*~SingleNode() {
          if (next != nullptr) {
            delete next;
            next = nullptr; 
        }
    }//destruktor*/
};


template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList(){
        for (SingleNode<T> *node; !empty(); ) {
        node = head->next; 
        delete head;
        head = node; 
    } }// tu trzeba wyczyscic wezly
  SingleList(const SingleList& other) {
    head = nullptr;
    tail = nullptr;
    SingleNode<T> *otherList = other.head;
    while (other.head != nullptr) {
        SingleNode<T> *newNode = new SingleNode<T>(otherList->value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        otherList = otherList->next;
    }
} // copy constructor
    // usage:   SingleList<int> list2(list1);

   // SingleList(SingleList&& other); // move constructor NIEOBOWIAZKOWE
    // usage:   SingleList<int> list2(std::move(list1));

    SingleList& operator=(const SingleList& other){
        if(this==&other){
            return *this;
        }

    while(head!=nullptr){
        SingleNode<T> *temp=head;
        head=head->next;
        delete temp;    
    } 
    tail=nullptr;
    
    SingleList<T> *otherList=other.head;
    while(otherList!=nullptr){
        SingleNode<T>*newNode=new SingleNode<T>(otherList->value);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
        otherList=otherList->next;
    }
    return *this;
    } // copy assignment operator, return *this
    // usage:   list2 = list1;

   // SingleList& operator=(SingleList&& other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE

    bool empty() const { 
        return head == nullptr; }
    int size() const{
        int i=0;
        SingleNode<T> *temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            i++;
        }
        return i;
    } // O(n) bo trzeba policzyc
    void push_front(const T& item){
        SingleNode<T>*newNode= new SingleNode<T>(item);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    } // O(1), L.push_front(item)
   // void push_front(T&& item); // O(1), L.push_front(std::move(item)) NIEOBOWIAZKOWE
    void push_back(const T& item){
        SingleNode<T>*newNode=new SingleNode<T>(item);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else{
        tail->next=newNode;
        tail=newNode;
        }} // O(1), L.push_back(item)
   // void push_back(T&& item); // O(1), L.push_back(std::move(item)) NIEOBOWIAZKOWE
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
  void pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
} // usuwa poczatek O(1)
    void pop_back(){
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
    }
 // usuwa koniec O(n)
    void clear(){
        if(head==nullptr){
            return;
        }else{
            while(head!=nullptr){
                SingleNode<T> *temp=head;
                head=head->next;
                delete temp;
            }
            tail=nullptr;
        }
    } // czyszczenie listy z elementow O(n)
  void display() {
    cout << "List size: " << size() << ", Elements: ";
    SingleNode<T> *temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
} // O(n)
    void reverse(){
        SingleNode<T> *akt=head;
        SingleNode<T> *poprzedni=nullptr;
        SingleNode<T> *next=nullptr;

        while(akt!=nullptr){
            next=akt->next;
            akt->next=poprzedni;

            poprzedni=akt;
            akt=next;
        }
    head=poprzedni;
    } // O(n)

   /*  // Operacje z indeksami. NIEOBOWIAZKOWE
    T& operator[](int pos); // podstawienie L[pos]=item, odczyt L[pos]
    const T& operator[](int pos) const; // dostep do obiektu const
    void erase(int pos);
    int index(const T& item); // jaki index na liscie (-1 gdy nie ma) O(n)
    void insert(int pos, const T& item); // inserts item before pos,
    void insert(int pos, T&& item); // inserts item before pos,
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.
}; */

/*template <typename T>
SingleList<T>::~SingleList() {
    // I sposob.
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
    // II sposob.
    // while (!empty()) { pop_front(); }
}

 template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}*/};

#endif