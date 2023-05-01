#ifndef INCLUDE_TREE_HPP
#define INCLUDE_TREE_HPP

#include "Node.hpp"
#include "vector.hpp"


template <typename T>
class Tree {
    private:
        Node<T>* root = nullptr;
        Node<T>* insert(const T&, Node<T>*);
        void inorder(Node<T>*);
        void clearTree(Node<T>*);
        Vector<int>* vec;

    public:
        Tree();
        Tree(const T&);
        ~Tree();
        void insert(const T&);
        void inorder();
        void task();
};

#include "../src/Tree.cpp"

#endif