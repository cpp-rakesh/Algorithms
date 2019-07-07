/*
  Node for Binary search tree
  07/07/2019
 */

#ifndef ALGORITHMS_TREE_BST_NODE_H_
#define ALGORITHMS_TREE_BST_NODE_H_

#include <cstddef>

template <typename T>
class Node {
public:
    Node();
    Node(T val);
    ~Node();

    T data() const;
    Node<T>* left() const;
    Node<T>* right() const;

    void left(Node<T>* n);
    void right(Node<T>* n);

private:
    T m_data;
    Node<T>* m_left;
    Node<T>* m_right;
};

template <typename T>
Node<T>::Node() : m_data(0), m_left(NULL), m_right(NULL) {}

template <typename T>
Node<T>::Node(T val) : m_data(val), m_left(NULL), m_right(NULL) {}

template <typename T>
T Node<T>::data() const {
    return m_data;
}

template <typename T>
Node<T>* Node<T>::left() const {
    return m_left;
}

template <typename T>
Node<T>* Node<T>::right() const {
    return m_right;
}

template <typename T>
void Node<T>::left(Node<T>* n) {
    m_left = n;
}

template <typename T>
void Node<T>::right(Node<T>* n) {
    m_right = n;
}

#endif // ALGORITHMS_TREE_BST_NODE_H_
