#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T& data){
    this->data = data;
    leftNode = nullptr;
    rightNode = nullptr;
}

template<typename T>
T Node<T>::getData() {
    return data;
}

template<typename T>
Node<T>* Node<T>::getLeftNode() {
    return leftNode;
}

template<typename T>
Node<T>* Node<T>::getRightNode() {
    return rightNode;
}

template<typename T>
void Node<T>::setRightNode(Node<T>* rightNode) {
    this->rightNode = rightNode;
}

template<typename T>
void Node<T>::setLeftNode(Node<T>* leftNode) {
    this->leftNode = leftNode;
}