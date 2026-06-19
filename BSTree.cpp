//
// Created by Juliana Suarez

#ifndef BSTREE_CPP
#define BSTREE_CPP
#include "BSTree.h"

//push
template<typename T>
Node<T>* BSTree<T>::push(Node<T>* node, const T& data)
{
    if (node == nullptr)
        return new Node<T>{data};

    if (data < node->data)
        node->left = push(node->left, data);

    else if (data > node->data)
        node->right = push(node->right, data);

    return node;
}

// min value
template<typename T>
Node<T>* BSTree<T>::minValue(Node<T>* node)
{
    Node<T>* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

//remove
template<typename T>
Node<T>* BSTree<T>::remove(Node<T>* node, const T& data)
{
    if (node == nullptr)
        return node;

    if (data < node->data)
        node->left = remove(node->left, data);

    else if (data > node->data)
        node->right = remove(node->right, data);

    else
    {
        if (node->left == nullptr)
        {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        }

        else if (node->right == nullptr)
        {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }

        Node<T>* temp = minValue(node->right);

        node->data = temp->data;

        node->right = remove(node->right, temp->data);
    }

    return node;
}

//clear
template<typename T>
void BSTree<T>::clear(Node<T>* node)
{
    if (node)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<typename T>
void BSTree<T>::clear()
{
    clear(root);
    root = nullptr;
}

//copy
template<typename T>
Node<T>* BSTree<T>::copy(Node<T>* node)
{
    if (node == nullptr)
        return nullptr;

    Node<T>* newNode = new Node<T>{node->data};

    newNode->height = node->height;

    newNode->left = copy(node->left);
    newNode->right = copy(node->right);

    return newNode;
}

template<typename T>
BSTree<T>::BSTree(const BSTree<T>& other)
{
    root = copy(other.root);
}

//operator=
template<typename T>
BSTree<T>& BSTree<T>::operator=(const BSTree<T>& other)
{
    if (this != &other)
    {
        clear();
        root = copy(other.root);
    }

    return *this;
}

//in order
template<typename T>
void BSTree<T>::inorder(Node<T>* node, void (*f)(T&))
{
    if (node)
    {
        inorder(node->left, f);
        f(node->data);
        inorder(node->right, f);
    }
}

//pre order
template<typename T>
void BSTree<T>::preorder(Node<T>* node, void (*f)(T&))
{
    if (node)
    {
        f(node->data);
        preorder(node->left, f);
        preorder(node->right, f);
    }
}

//post order
template<typename T>
void BSTree<T>::postorder(Node<T>* node, void (*f)(T&)) {
    if (node) {
        postorder(node->left, f);
        postorder(node->right, f);
        f(node->data);
    }
}

//traversal
template<typename T>
void BSTree<T>::setTraversal(Traversal t)
{
    traversal = t;
}

//traverse
template<typename T>
void BSTree<T>::traverse(void (*f)(T&))
{
    switch (traversal)
    {
        case PREORDER:
            preorder(root, f);
            break;

        case INORDER:
            inorder(root, f);
            break;

        case POSTORDER:
            postorder(root, f);
            break;
    }
}
//destructor
template<typename T>
BSTree<T>::~BSTree()
{
    clear();
}

//print
template<typename T>
void BSTree<T>::print()
{
    traverse();
    std::cout << std::endl;
}
#endif
