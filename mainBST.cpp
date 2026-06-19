//
// Created by Juliana Suarez
//
#include <iostream>
#include "AVLTree.h"



int main()
{
    AVLTree<int> tree;

    int values[] = {6, 20, 61, 72, 40, 4, 30, 16, 1};

    for (int v : values)
        tree.push(v);

    std::cout << "INORDER: " << std::endl;
    tree.setTraversal(INORDER);
    tree.print();

    std::cout << "PREORDER: " << std::endl;
    tree.setTraversal(PREORDER);
    tree.print();

    std::cout << "POSTORDER: " << std::endl;
    tree.setTraversal(POSTORDER);
    tree.print();

    std::cout << "Remove 20: " << std::endl;
    tree.remove(20);
    tree.setTraversal(INORDER);
    tree.print();

    std::cout << "Copy tree: " << std::endl;

    BSTree<int> copyTree = tree;
    copyTree.print();

    std::cout << "Clear original tree: " << std::endl;
    tree.clear();
    tree.print();

    std::cout << "Copied tree still exists: " << std::endl;
    copyTree.print();

    return 0;
}
