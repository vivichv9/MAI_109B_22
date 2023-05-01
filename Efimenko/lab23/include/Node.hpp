#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>

template<typename T>
class Node {
private:
    T data;
    Node<T>* leftNode;
    Node<T>* rightNode;
public:
    T getData();
    Node<T>* getLeftNode();
    Node<T>* getRightNode();
    void setLeftNode(Node<T>*);
    void setRightNode(Node<T>*);
    Node(const T&);
};

#include "../src/Node.cpp"

#endif


