#include <bits/stdc++.h>

using V = std::vector<int>;
using M = std::map<int, V>;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BT {
public:
    BT() : m_root(nullptr) {}
    ~BT() {}

    void insert(int val) {
        Node* node = m_create(val);
        if (m_root == nullptr) {
            m_root = node;
        } else {
            std::queue<Node*> q;
            q.push(m_root);

            while (1) {
                Node* n = q.front();
                q.pop();

                if (n->left == nullptr) {
                    n->left = node;
                    break;
                } else {
                    q.push(n->left);
                }

                if (n->right == nullptr) {
                    n->right = node;
                    break;
                } else {
                    q.push(n->right);
                }
            }
        }
    }

    void remove(int val) {
        Node* last = m_last();
        if (m_swap(val, last->data)) {
            std::queue<Node*> q;
            q.push(m_root);

            while (1) {
                Node* node = q.front();
                q.pop();
                if (node->left == last) {
                    node->left = nullptr;
                    delete last;
                    break;
                } else {
                    q.push(node->left);
                }

                if (node->right == last) {
                    node->right = nullptr;
                    delete last;
                    break;
                } else {
                    q.push(node->right);
                }
            }
        }
    }

    int height() const {
        return m_height(m_root);
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

    void level() const {
        M m;
        m_level(m_root, m, 0);
        printf("------------------------------------------------\n");
        for (auto it = m.begin(); it != m.end(); ++it) {
            for (const auto& x : it->second)
                printf("%d ", x);
            printf("\n");
        }
        printf("------------------------------------------------\n");
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

    Node* m_last() const {
        Node* node = nullptr;
        if (m_root != nullptr) {
            std::queue<Node*> q;
            q.push(m_root);

            while (!q.empty()) {
                node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return node;
    }

    bool m_swap(int a, int b) {
        if (m_root != nullptr) {
            std::queue<Node*> q;
            q.push(m_root);

            while (!q.empty()) {
                Node* node = q.front();
                q.pop();

                if (node->data == a) {
                    node->data = b;
                    return true;
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return false;
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

    int m_height(Node* node) const {
        if (node == nullptr)
            return 0;
        const int lh = m_height(node->left) + 1;
        const int rh = m_height(node->right) + 1;
        return std::max(lh, rh);
    }

    Node* m_root;
};

int main() {
    BT bt;
    for (int i = 1; i <= 100; ++i)
        bt.insert(i);

    bt.level();

    bt.remove(7);

    bt.level();

    printf("Height of the tree == [%d]\n", bt.height());

    return 0;
}
