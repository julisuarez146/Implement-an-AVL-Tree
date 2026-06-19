//
// Created by Juliana Suarez.
//

#ifndef AVLTREE_H
#define AVLTREE_H
#include "BSTree.h"

template<typename T>
class AVLTree : public BSTree<T>
{
private:
    using BSTree<T>::root;

    int height(Node<T>* node);

public:
//AVL func.
    int balanceFactor(Node<T>* node);

    void balance(Node<T>* &node);

    void rotate(Node<T>* &node,
                Node<T>* &heavyChild,
                Node<T>* &heavyChildSubtree);

    void rotateLeft(Node<T>* &node);

    void rotateRight(Node<T>* &node);

    void push(const T& data)
    {
        this->root = push(this->root, data);
    }

    void remove(const T& data)
    {
        this->root = remove(this->root, data);
    }

protected:
    Node<T>* push(Node<T>* node, const T& data) override;

    Node<T>* remove(Node<T>* node, const T& data) override;
};

#include "AVLTree.cpp"
#endif //AVLTREE_H
