#include <iostream>

struct Node {
    int value;
    Node *left, *right;
    Node(int val);
    ~Node();
    bool search(int n) const;
    bool insert(int n);
};

Node::Node(int val): value(val) {
    left = right = NULL;
}

Node::~Node() {};

bool Node::search(int n) const {
    if (this == NULL) return false;
    if (n == value) return true;
    if (n < value) return left->search(n);
    return right->search(n);
}

bool Node::insert(int n) {
    if (n == value) return false;
    if (n < value) {
        if (left == NULL) {
            left = new Node(n);
            return true;
        }
        else return left->insert(n);
    }
    
    if (right == NULL) {
        right == new Node(n);
        return true;
    }
    else return left->insert(n);
}

