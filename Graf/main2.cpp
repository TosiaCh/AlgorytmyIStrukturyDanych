#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node{
string name;
vector<Node*> listaSasiadow;
Node(string n): name(n), listaSasiadow() {};
};

class Graph{
unorthered_map <string, Node* > nodes;

void dodajNode(string name){
    Node* node = new Node(name);
    nodes[name]= node;
}

void dodajPolaczenie(string n1, string n2){
    nodes[n1]->listaSasiadow.push_back(nodes[n2]);
    nodes[n2]->listaSasiadow.push_back(nodes[n1]);
}

};




