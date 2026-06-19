//
// Created by Juliana Suarez
//

#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node *left = nullptr, *right = nullptr;
    int height = 1;
};

// enum to set the traversal of the tree
enum Traversal {
    PREORDER, INORDER, POSTORDER
};

template<typename T>
class BSTree {

protected:
    Node<T>* root = nullptr;
    Traversal traversal = INORDER;

    virtual Node<T>* push(Node<T>* node, const T& data);
    virtual Node<T>* remove(Node<T>* node, const T& data);

    Node<T>* minValue(Node<T>* node);

    void clear(Node<T>* node);

    Node<T>* copy(Node<T>* node);

    void inorder(Node<T>* node, void (*f)(T&));
    void preorder(Node<T>* node, void (*f)(T&));
    void postorder(Node<T>* node, void (*f)(T&));

public:
    BSTree() = default;

    // copy cons
    BSTree(const BSTree<T>& other);

    // assignment operator
    BSTree<T>& operator=(const BSTree<T>& other);

    // destructor
    ~BSTree();

    // functions
    void push(const T& data);
    void remove(const T& data);
    void clear();
    void setTraversal(Traversal traversal);
    void traverse(void (*f)(T&) = [](T& data) {
        std::cout << data << " ";
    });

    void print();
};


#include "BSTree.cpp"
#endif //BSTREE_H
