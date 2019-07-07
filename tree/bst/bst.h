/*
  Binary search tree
  07/07/2019
 */

#ifndef ALGORITHMS_TREE_BST_BST_H_
#define ALGORITHMS_TREE_BST_BST_H_

#include "node.h"
#include <cstdio>

template <typename T>
class BST {
public:
    BST();
    ~BST();

    void insert(T val);
    void pre_order() const;
    void in_order() const;
    void post_order() const;
    bool search(T val) const;

private:
    void m_pre_order(Node<T>* n) const;
    void m_in_order(Node<T>* n) const;
    void m_post_order(Node<T>* n) const;

    Node<T>* m_root;
};

template <typename T>
BST<T>::BST() : m_root(NULL) {}

template <typename T>
BST<T>::~BST() {}

template <typename T>
void BST<T>::insert(T val) {
    Node<T>* n = new Node<T>(val);
    if (m_root == nullptr) {
        m_root = n;
    } else {
        Node<T>* c = m_root;
        while (1) {
            // left side
            if (val <= c->data()) {
                if (c->left() == nullptr) {
                    c->left(n);
                    break;
                } else {
                    c = c->left();
                }
            } else { // right side
                if (c->right() == nullptr) {
                    c->right(n);
                    break;
                } else {
                    c = c->right();
                }
            }
        }
    }
}

template <typename T>
void BST<T>::pre_order() const {
    m_pre_order(m_root);
    printf("\n");
}

template <typename T>
void BST<T>::in_order() const {
    m_in_order(m_root);
    printf("\n");
}

template <typename T>
void BST<T>::post_order() const {
    m_post_order(m_root);
    printf("\n");
}

template <typename T>
void BST<T>::m_pre_order(Node<T>* n) const {
    if (n != nullptr) {
        printf("%d ", n->data());
        m_pre_order(n->left());
        m_pre_order(n->right());
    }
}

template <typename T>
void BST<T>::m_in_order(Node<T>* n) const {
    if (n != nullptr) {
        m_pre_order(n->left());
        printf("%d ", n->data());
        m_pre_order(n->right());
    }
}

template <typename T>
void BST<T>::m_post_order(Node<T>* n) const {
    if (n != nullptr) {
        m_pre_order(n->left());
        m_pre_order(n->right());
        printf("%d ", n->data());
    }
}

template <typename T>
bool BST<T>::search(T val) const {
    Node<T>* c = m_root;
    while (c != nullptr) {
        if (c->data() == val)
            return true;
        else if(val < c->data())
            c = c->left();
        else
            c = c->right();
    }

    return false;
}

#endif // ALGORITHMS_TREE_BST_BST_H_
