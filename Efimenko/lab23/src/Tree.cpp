#include <iostream>
#include "../include/Tree.hpp"
#include "../include/Node.hpp"
#include "../include/vector.hpp"

template <typename T>
Tree<T>::Tree(const T& data) {
    root = new Node<T>(data);
    this->root = root;
}

template <typename T>
Tree<T>::Tree() {
    root = new Node<T>(NULL);
    vec = new Vector<int>();
}

template <typename T>
Node<T>* Tree<T>::insert(const T& data, Node<T>* temp) {
    if(temp == nullptr) {
        temp = new Node<int>(data);
        temp->setLeftNode(nullptr);
        temp->setRightNode(nullptr);
    }
    else if(data < temp->getData())
        temp->setLeftNode(insert(data, temp->getLeftNode()));
    else if(data > temp->getData())
        temp->setRightNode(insert(data, temp->getRightNode()));
    return temp;
}

template <typename T>
void Tree<T>::insert(const T& data) {
    root = insert(data, root);
}

template <typename T>
void Tree<T>::inorder(Node<T>* temp) {
    if (temp == nullptr) {
        return;
    }
    inorder(temp->getLeftNode());

    if (temp->getLeftNode() != nullptr and temp->getRightNode() != nullptr) {
        vec->pushBack(temp->getData());
    }

    inorder(temp->getRightNode());
}

template <typename T>
void Tree<T>::task() {
    inorder(root);
    std::cout << vec->getSize() << '\n';
}

template <typename T>
void Tree<T>::clearTree(Node<T>* node) {
    if (root == nullptr) {
        return;
    }
    
    clearTree(node->getLeftNode());
    clearTree(node->getRightNode());
    delete node;
}

template <typename T>
Tree<T>::~Tree() {
    clearTree(root);
    delete vec;
}
