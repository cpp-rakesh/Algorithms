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

    void pre_order(Node* node, std::vector<int>& v) {
        if (node == nullptr)
            return;
        v.emplace_back(node->val);
        pre_order(node->left, v);
        pre_order(node->right, v);
    }

    void in_order(Node* node, std::vector<int>& v) {
        if (node == nullptr)
            return;
        in_order(node->left, v);
        v.emplace_back(node->val);
        in_order(node->right, v);
    }

    void post_order(Node* node, std::vector<int>& v) {
        if (node == nullptr)
            return;
        post_order(node->left, v);
        post_order(node->right, v);
        v.emplace_back(node->val);
    }

    Node* build_from_pre_order(const std::vector<int>& v, int upper_bound = INT_MAX) {
        if (i == v.size() || v[i] > upper_bound)
            return nullptr;
        Node* node = new Node(v[i++]);
        node->left = build_from_pre_order(v, node->val);
        node->right = build_from_pre_order(v, upper_bound);
        return node;
    }

    Node* build_from_in_order(const std::vector<int>& v, int s = 0, int e = 0) {
        if (s > e)
            return nullptr;
        const int mid = (s + e) >> 1;
        Node* root = new Node(v[mid]);
        root->left = build_from_in_order(v, s, mid - 1);
        root->right = build_from_in_order(v, mid + 1, e);
        return root;
    }

    Node* build_from_post_order(const std::vector<int>& v, int lower_bound = INT_MIN) {
        if (i == -1 || v[i] < lower_bound)
            return nullptr;
        Node* root = new Node(v[i--]);
        root->right = build_from_post_order(v, root->val);
        root->left = build_from_post_order(v, lower_bound);
        return root;
    }

    void reset(int val) {
        i = val;
    }

private:
    int i = 0;
};

inline void print(const std::vector<int>& v) {
    printf("------------------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n------------------------------------------------------------\n");
}

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

void test_2() {
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
    root = bst.insert(root, 10);
    root = bst.insert(root, 5);
    root = bst.insert(root, 1);
    bst.bfs(root);
    std::vector<int> v1;
    printf("               pre order traversal\n");
    bst.pre_order(root, v1);
    print(v1);
    std::vector<int> v2;
    printf("               in order traversal\n");
    bst.in_order(root, v2);
    print(v2);
    std::vector<int> v3;
    printf("               post order traversal\n");
    bst.post_order(root, v3);
    print(v3);
}

void test_3() {
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
    root = bst.insert(root, 10);
    root = bst.insert(root, 5);
    root = bst.insert(root, 1);
    bst.bfs(root);
    std::vector<int> v;
    bst.pre_order(root, v);
    print(v);
    Node* node_from_pre_order = bst.build_from_pre_order(v);
    bst.bfs(node_from_pre_order);
}

void test_4() {
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
    root = bst.insert(root, 10);
    root = bst.insert(root, 5);
    root = bst.insert(root, 1);
    bst.bfs(root);
    std::vector<int> v;
    bst.in_order(root, v);
    print(v);
    Node* node_from_in_order = bst.build_from_in_order(v, 0, static_cast<int>(v.size()) - 1);
    bst.bfs(node_from_in_order);
}

void test_5() {
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
    root = bst.insert(root, 10);
    root = bst.insert(root, 5);
    root = bst.insert(root, 1);
    bst.bfs(root);
    std::vector<int> v;
    bst.post_order(root, v);
    print(v);
    bst.reset(v.size() - 1);
    Node* node_from_post_order = bst.build_from_post_order(v);
    bst.bfs(node_from_post_order);
}


int main() {
    //test_1();
    //test_2();
    //test_3();
    //test_4();
    test_5();

    return 0;
}
