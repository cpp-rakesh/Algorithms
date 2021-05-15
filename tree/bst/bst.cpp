/*
  Rakesh Kumar
  Year of devestating pandemic
  Never stop learning !!!
 */

#include <bits/stdc++.h>

struct Node {
    Node() {}
    Node(int val) : val(val) {}

    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BST {
public:
    Node* insert(Node* root, int val) {
        if (root == nullptr)
            root = new Node(val);
        else {
            Node* node = root;
            while (node) {
                if (val < node->val) {
                    if (node->left == nullptr) {
                        node->left = new Node(val);
                        break;
                    } else
                        node = node->left;
                } else {
                    if (node->right == nullptr) {
                        node->right = new Node(val);
                        break;
                    } else
                        node = node->right;
                }
            }
        }
        return root;
    }

    void bfs(Node* node) {
        printf("------------------------------------------------------------\n");
        printf("                     level order traversal\n");
        std::queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                node = q.front(); q.pop();
                printf("%d ", node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            printf("\n");
        }
        printf("------------------------------------------------------------\n");
    }
};

void test_1() {
    BST bst;
    Node* root = nullptr;
    root = bst.insert(root, 100);
    root = bst.insert(root, 50);
    root = bst.insert(root, 150);
    root = bst.insert(root, 25);
    root = bst.insert(root, 60);
    root = bst.insert(root, 130);
    root = bst.insert(root, 175);
    root = bst.insert(root, 165);
    root = bst.insert(root, 155);
    root = bst.insert(root, 200);
    root = bst.insert(root, 250);
    root = bst.insert(root, 300);
    root = bst.insert(root, 25);
    root = bst.insert(root, 10);
    root = bst.insert(root, 5);
    root = bst.insert(root, 1);
    bst.bfs(root);
}

int main() {
    test_1();

    return 0;
}
