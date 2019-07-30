#ifndef ALGORITHMS_TREE_BINARY_BT_H_
#define ALGORITHMS_TREE_BINARY_BT_H_

#include "../common/node.h"
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using V = std::vector<int>;
using M = std::map<int, V>;

template <typename T>
class BT {
public:
    BT();
    ~BT();

    void insert(T val);
    void pre_order() const;
    void in_order() const;
    void post_order() const;
    void bfs() const;
    void level() const;
    void remove(T val);

private:
    void m_pre_order(Node<T>* node) const;
    void m_in_order(Node<T>* node) const;
    void m_post_order(Node<T>* node) const;
    void m_level(M& m, Node<T>* node, int level) const;
    Node<T>* m_last_node() const;

    Node<T>* m_root;
};

template <typename T>
BT<T>::BT() : m_root(nullptr) {}

template <typename T>
BT<T>::~BT() {
    if (m_root) delete m_root;
}

template <typename T>
void BT<T>::insert(T val) {
    Node<T>* node = new Node<T>(val);

    if (m_root == nullptr) {
        m_root = node;
    } else {
        std::queue<Node<T>* > q;
        q.push(m_root);

        while (!q.empty()) {
            Node<T>* n = q.front();
            q.pop();
            if (n->left()) {
                q.push(n->left());
            } else {
                n->left(node);
                break;
            }

            if (n->right()) {
                q.push(n->right());
            } else {
                n->right(node);
                break;
            }
        }
    }
}

template <typename T>
void BT<T>::pre_order() const {
    printf("------------- pre  order traversal --------------\n");
    m_pre_order(m_root);
    printf("\n");
}

template <typename T>
void BT<T>::in_order() const {
    printf("------------- in   order traversal --------------\n");
    m_in_order(m_root);
    printf("\n");
}

template <typename T>
void BT<T>::post_order() const {
    printf("------------- post order traversal --------------\n");
    m_post_order(m_root);
    printf("\n");
}

template <typename T>
void BT<T>::bfs() const {
    std::queue<Node<T>* > q;
    if (m_root)
        q.push(m_root);
    while (!q.empty()) {
        Node<T>* n = q.front();
        q.pop();
        printf("%d ", n->data());
        if (n->left())
            q.push(n->left());
        if (n->right())
            q.push(n->right());
    }
    printf("\n");
}

template <typename T>
void BT<T>::level() const {
    printf("------------- level  traversal --------------\n");
    M m;
    m_level(m, m_root, 0);
    for (auto it = m.begin(); it != m.end(); ++it) {
        printf("----------------- [%d] level ------------------\n", it->first);
        for (const auto& x : it->second)
            printf("%d ", x);
        printf("\n-----------------------------------------------\n");
    }
}

template <typename T>
void BT<T>::remove(T val) {
    if (m_root == nullptr)
        return;
    if (m_root->left() == nullptr) {
        if (m_root->data() == val) {
            m_root = nullptr;
            return;
        }
    }

    Node<T>* last_node = m_last_node();
    std::queue<Node<T>* > q;
    q.push(m_root);

    while(!q.empty()) {
        Node<T>* node = q.front();
        q.pop();
        if (node->data() == val)
            node->data(last_node->data());
        if (node->left() != nullptr) {
            if (node->left() == last_node)
                node->left(nullptr);
            else
                q.push(node->left());
        }
        if (node->right() != nullptr) {
            if (node->right() == last_node)
                node->right(nullptr);
            else
                q.push(node->right());
        }
    }
}

template <typename T>
void BT<T>::m_pre_order(Node<T>* node) const {
    if (node) {
        printf("%d ", node->data());
        m_pre_order(node->left());
        m_pre_order(node->right());
    }
}

template <typename T>
void BT<T>::m_in_order(Node<T>* node) const {
    if (node) {
        m_in_order(node->left());
        printf("%d ", node->data());
        m_in_order(node->right());
    }
}

template <typename T>
void BT<T>::m_post_order(Node<T>* node) const {
    if (node) {
        m_post_order(node->left());
        m_post_order(node->right());
        printf("%d ", node->data());
    }
}

template <typename T>
void BT<T>::m_level(M& m, Node<T>* node, int level) const {
    if (node != nullptr) {
        m[level].push_back(node->data());
        m_level(m, node->left(), level + 1);
        m_level(m, node->right(), level + 1);
    }
}

template <typename T>
Node<T>* BT<T>::m_last_node() const {
    Node<T>* temp_node = nullptr;

    if (m_root != nullptr) {
        std::queue<Node<T>* > q;
        q.push(m_root);

        while (!q.empty()) {
            temp_node = q.front();
            q.pop();
            if (temp_node->left()) q.push(temp_node->left());
            if (temp_node->right()) q.push(temp_node->right());
        }
    }

    return temp_node;
}

#endif // ALGORITHMS_TREE_BINARY_BT_H_
