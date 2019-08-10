#include <bits/stdc++.h>

struct Node {
    int data;
    Node* left;
    Node* right;
};

using V = std::vector<int>;
using M = std::map<int, V>;

class BST {
public:
    BST() : m_root(nullptr) {}
    ~BST() {}

    void insert(int val) {
        Node* node = m_create(val);
        if (m_root == nullptr) {
            m_root = node;
        } else {
            Node* cur = m_root;
            while (1) {
                if (val < cur->data) {
                    if (cur->left == nullptr) {
                        cur->left = node;
                        break;
                    } else {
                        cur = cur->left;
                    }
                } else if (val > cur->data) {
                    if (cur->right == nullptr) {
                        cur->right = node;
                        break;
                    } else {
                        cur = cur->right;
                    }
                } else {
                    return;
                }
            }
        }
    }

    void level() const {
        M m;
        m_level(m_root, m, 0);
        printf("-------------------------------------------\n");
        for (auto it = m.begin(); it != m.end(); ++it) {
            for (const auto& x : it->second)
                printf("%d ", x);
            printf("\n");
        }
        printf("-------------------------------------------\n");
    }

    void pre_order() const {
        m_pre_order(m_root);
        printf("\n");
    }

    void in_order() const {
        m_in_order(m_root);
        printf("\n");
    }

    void post_order() const {
        m_post_order(m_root);
        printf("\n");
    }

private:
    Node* m_create(int val) {
        Node* node = new Node;
        node->data = val;
        node->left = node->right = nullptr;

        return node;
    }

    void m_level(Node* node, M& m, int level) const {
        if (node != nullptr) {
            m[level].push_back(node->data);
            m_level(node->left, m, level + 1);
            m_level(node->right, m, level + 1);
        }
    }

    void m_pre_order(Node* node) const {
        if (node != nullptr) {
            printf("%d ", node->data);
            m_pre_order(node->left);
            m_pre_order(node->right);
        }
    }

    void m_in_order(Node* node) const {
        if (node != nullptr) {
            m_in_order(node->left);
            printf("%d ", node->data);
            m_in_order(node->right);
        }
    }

    void m_post_order(Node* node) const {
        if (node != nullptr) {
            m_post_order(node->left);
            m_post_order(node->right);
            printf("%d ", node->data);
        }
    }

    Node* m_root;
};

int main() {
    BST bst;
    bst.insert(200);
    bst.insert(100);
    bst.insert(500);
    bst.insert(180);
    bst.insert(10);
    bst.insert(5);

    bst.level();
    bst.pre_order();
    bst.in_order();
    bst.post_order();

    return 0;
}
