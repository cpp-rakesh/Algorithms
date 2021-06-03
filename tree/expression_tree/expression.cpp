/*
  Rakesh Kumar
  Year of devestating pandemic
  Never stop learning !!!
 */

#include <bits/stdc++.h>

struct Node {
    Node() {}
    Node(int val, char op) : val(val), op(op) {}
    int val = 0;
    char op = 'X';
    Node* left = nullptr;
    Node* right = nullptr;
};

int eval(Node* node) {
    if (node == nullptr)
        return 0;
    if (node->op == 'X')
        return node->val;
    int a = eval(node->left);
    int b = eval(node->right);
    int res = 0;
    if (node->op == '+')
        res = a + b;
    else if (node->op == '-')
        res = a - b;
    else if (node->op == '*')
        res = a * b;
    else
        if (b)
            res = a / b;
    return res;
}

void test_a() {
    Node* root = new Node(0, '+');
    root->left = new Node(0, '*');
    root->right = new Node(0, '-');
    root->left->left = new Node(5, 'X');
    root->left->right = new Node(4, 'X');
    root->right->left = new Node(100, 'X');
    root->right->right = new Node(20, 'X');
    printf("%d\n", eval(root));
}

void test_b() {
    Node* root = new Node(0, '+');
    root->left = new Node(0, '*');
    root->right = new Node(0, '-');
    root->left->left = new Node(5, 'X');
    root->left->right = new Node(4, 'X');
    root->right->left = new Node(100, 'X');
    root->right->right = new Node(0, '/');
    root->right->right->left = new Node(20, 'X');
    root->right->right->right = new Node(2, 'X');
    printf("%d\n", eval(root));
}

int main() {
    test_a();
    test_b();

    return 0;
}
