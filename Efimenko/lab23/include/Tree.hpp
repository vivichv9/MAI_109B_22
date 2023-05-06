#ifndef INCLUDE_TREE_HPP
#define INCLUDE_TREE_HPP

#include "Node.hpp"
#include "vector.hpp"

template <typename T>
class Tree {
    private:
        Node<T>* root = nullptr;
        Vector<int>* vec = new Vector<int>();

        Node<T>* insert(const T&, Node<T>*);
        void bypass(Node<T>*);
        void clearTree(Node<T>*);

    public: 
        Tree() = default;;
        Tree(const T&);
        ~Tree();

        void insert(const T&);
        void bypass();
        void task();
};

#include "../src/Tree.cpp"

#endif