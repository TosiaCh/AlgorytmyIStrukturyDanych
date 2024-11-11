//Zadanie 10.1


#include <iostream>
#include <cassert>
#include <stack>
// Szablon dla węzła drzewa binarnego i drzewa BST.
template <typename T>
struct BSTNode {
// the default access mode and default inheritance mode are public
    T value;
    BSTNode *left, *right;
    //BSTNode *parent;   // używane w pewnych zastosowaniach
    // kostruktor domyślny
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    // konstruktor zwykły
    BSTNode(const T& item) : value(item), left(nullptr), right(nullptr) {}
    ~BSTNode() {} // destruktor
};

// Szablon dla przypadkowego drzewa binarnego.
template <typename T>
class RandomBinaryTree {
    BSTNode<T> *root;
public:
    RandomBinaryTree() : root(nullptr) {} // konstruktor domyślny
    ~RandomBinaryTree() { clear(); } // trzeba wyczyścić
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root->value; } // podgląd korzenia
    void insert(const T& item) { root = insert(root, item); }
    //void remove(const T& item); // na razie nie usuwamy elementów
    // Szukając element dostajemy wskaźnik do elementu lub nullptr.
    T* search(const T& item) const {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    T* find_min();
    T* find_max();
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    void iter_preorder();
    void iter_inorder(); // trudne
    void iter_postorder(); // trudne
    void bfs(); // przejście poziomami (wszerz)
    void clear() { clear(root); root = nullptr; }
    void display() { display(root, 0); }

    // Metody bezpośrednio odwołujące się do node.
    // Mogą działać na poddrzewie.
    void clear(BSTNode<T> *node){
        if(node != nullptr){
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
    BSTNode<T> * insert(BSTNode<T> *node, const T& item){
        if(node == nullptr){
            return new BSTNode<T>(item);
        }
        if(item < node->value){
            node->left = insert(node->left,item);
        } else if(item > node->value){
            node->right = insert(node->right,item);
        }
        return node;

    } // zwraca nowy korzeń
    BSTNode<T> * search(BSTNode<T> *node, const T& item) const;
    void preorder(BSTNode<T> *node);
    void inorder(BSTNode<T> *node);
    void postorder(BSTNode<T> *node);
    void display(BSTNode<T> *node, int level);
    virtual void visit(BSTNode<T> *node) {
        assert(node != nullptr);
        std::cout << "visiting " << node->value << std::endl;
    }
    int calc_leavesR(){
        return calc_leavesR(root);
    }
    int calc_leavesIT(){
        return calc_leavesIT(root);
    }

    private :
    //funkcja licząca iteracyjnie ilość liści w drzewie
    int calc_leavesIT(BSTNode<T>* node){
        if(node == nullptr){
            return 0;
        }
        int ileLisci=0;
        std::stack<BSTNode<T>*> S;
        S.push(root);
        while(!S.empty()){
            BSTNode<T>* akt = S.top();
            S.pop();

            if(akt->left == nullptr && akt->right == nullptr){
                ileLisci++;
            }
            if(akt->right != nullptr){
                S.push(akt->right);
            }
            if(akt->left != nullptr){
                S.push(akt->left);
            }
        }
       return ileLisci; 
    }
    //funkcja licząca iteracyjnie ilość liści w drzewie
    int calc_leavesR (BSTNode<T>* node){
    if (node == nullptr){
        return 0;
    }
    if(node->left == nullptr && node->right == nullptr){
        return 1;
    }
    else {
        return calc_leavesR(node->left) + calc_leavesR(node->right);
    } }
};

