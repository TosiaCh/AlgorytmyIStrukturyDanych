#include <iostream>
#include "tree.h"


int main() {
    RandomBinaryTree<int> myTree;

    // Wstawianie kilku elementów do drzewa
    myTree.insert(5);
    myTree.insert(3);
    myTree.insert(7);
    myTree.insert(2);
    myTree.insert(4);
    myTree.insert(6);
    myTree.insert(8);

    // Użycie funkcji calc_leaves
    int liczbaLisci = myTree.calc_leavesR();
    std::cout << "Liczba lisci w drzewie (rekurencja): " << liczbaLisci << std::endl;
    int liczbaLisciIteracyjnie = myTree.calc_leavesIT();
    std::cout << "Liczba lisci w drzewie (iteracja): " << liczbaLisciIteracyjnie <<std::endl;

    return 0;
}