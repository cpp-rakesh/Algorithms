/*
  Binary tree implemetation
  07/07/2019
 */

#ifndef ALGORITHMS_TREE_BINARY_BINARY_H_
#define ALGORITHMS_TREE_BINARY_BINARY_H_

#include "../common/node.h"
#include <cstdio>
#include <cstddef>
#include <queue>

template <typename T>
class Binary {
public:
    Binary();
    ~Binary();

    void insert(T val);
    void in_order() const;

private:
    void m_in_order(Node<T>* n) const;
    Node<T>* m_root;
};

template <typename T>
Binary<T>::Binary() : m_root(NULL) {}

template <typename T>
Binary<T>::~Binary() {
    if (m_root != nullptr)
        delete m_root;
}

template <typename T>
void Binary<T>::insert(T val) {
    Node<T>* n = new Node<T>(val);
    if (m_root == nullptr) {
        m_root = n;
    } else {
        std::queue<Node<T>*> queue;
        queue.push(m_root);

        while (!queue.empty()) {
            Node<T>* temp = queue.front();
            queue.pop();

            if (temp->left() == nullptr) {
                temp->left(n);
                break;
            } else {
                queue.push(temp->left());
            }

            if (temp->right() == nullptr) {
                temp->right(n);
                break;
            } else {
                queue.push(temp->right());
            }
        }
    }
}

template <typename T>
void Binary<T>::in_order() const {
    m_in_order(m_root);
    printf("\n");
}

template <typename T>
void Binary<T>::m_in_order(Node<T>* n) const {
    if (n != nullptr) {
        m_in_order(n->left());
        printf("%d ", n->data());
        m_in_order(n->right());
    }
}

#endif // ALGORITHMS_TREE_BINARY_BINARY_H_
