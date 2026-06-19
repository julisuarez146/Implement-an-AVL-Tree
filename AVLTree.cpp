//
// Created by Juliana Suarez.
//

#ifndef AVLTREE_CPP
#define AVLTREE_CPP

#include "AVLTree.h"

template<typename T>
int AVLTree<T>::height(Node<T>* node)
{
    return node == nullptr ? 0 : node->height;
}

template<typename T>
int AVLTree<T>::balanceFactor(Node<T>* node)
{
    return node == nullptr ? 0 :
           height(node->left) - height(node->right);
}

template<typename T>
void AVLTree<T>::rotate(Node<T>* &node,
                        Node<T>* &heavyChild,
                        Node<T>* &heavyChildSubtree)
{
    heavyChild->right = node;

    node->left = heavyChildSubtree;

    node->height = 1 + std::max(height(node->left),
                                height(node->right));

    heavyChild->height = 1 + std::max(height(heavyChild->left),
                                      height(heavyChild->right));

    node = heavyChild;
}

template<typename T>
void AVLTree<T>::rotateRight(Node<T>* &node)
{
    Node<T>* heavyChild = node->left;
    Node<T>* heavyChildSubtree = heavyChild->right;

    rotate(node, heavyChild, heavyChildSubtree);
}

template<typename T>
void AVLTree<T>::rotateLeft(Node<T>* &node)
{
    Node<T>* heavyChild = node->right;
    Node<T>* heavyChildSubtree = heavyChild->left;

    heavyChild->left = node;

    node->right = heavyChildSubtree;

    node->height = 1 + std::max(height(node->left),
                                height(node->right));

    heavyChild->height = 1 + std::max(height(heavyChild->left),
                                      height(heavyChild->right));

    node = heavyChild;
}

template<typename T>
void AVLTree<T>::balance(Node<T>* &node)
{
    int bf = balanceFactor(node);

    // LEFT
    if (bf > 1)
    {
        if (balanceFactor(node->left) < 0)
            rotateLeft(node->left);

        rotateRight(node);
    }

    // RIGHT
    else if (bf < -1)
    {
        if (balanceFactor(node->right) > 0)
            rotateRight(node->right);

        rotateLeft(node);
    }
}

template<typename T>
Node<T>* AVLTree<T>::push(Node<T>* node, const T& data)
{
    if (node == nullptr)
        return new Node<T>{data};

    if (data < node->data)
        node->left = push(node->left, data);

    else if (data > node->data)
        node->right = push(node->right, data);

    else
        return node;

    node->height = 1 + std::max(height(node->left),
                                height(node->right));

    balance(node);

    return node;
}

template<typename T>
Node<T>* AVLTree<T>::remove(Node<T>* node, const T& data)
{
    node = BSTree<T>::remove(node, data);

    if (node == nullptr)
        return node;

    node->height = 1 + std::max(height(node->left),
                                height(node->right));

    balance(node);

    return node;
}

#endif
