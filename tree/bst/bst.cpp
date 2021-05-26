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
        if (i == static_cast<int>(v.size()) || v[i] > upper_bound)
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

    std::vector<int> sort(Node* root, bool reverse) {
        std::vector<int> r;
        if (reverse)
            sort_reverse(root, r);
        else
            in_order(root, r);
        return r;
    }

    int sum(Node* root) {
        if (root == nullptr)
            return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

    int largest_subtree_sum(Node* root, int& res)  {
        if (root == nullptr)
            return 0;
        const int curr_sum = root->val + largest_subtree_sum(root->left, res) + largest_subtree_sum(root->right, res);
        res = std::max(curr_sum, res);
        return curr_sum;
    }

    bool sum_of_level(Node* root, int sum) {
        if (root) {
            std::queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                int total = 0;
                for (int i = static_cast<int>(q.size()); i > 0; --i) {
                    root = q.front(); q.pop();
                    total += root->val;
                    if (root->left) q.push(root->left);
                    if (root->right) q.push(root->right);
                }
                if (total == sum)
                    return true;
            }
        }
        return false;
    }

    int min(Node* root) {
        while (root->left)
            root = root->left;
        return root->val;
    }

    int max(Node* root) {
        while (root->right)
            root = root->right;
        return root->val;
    }

    void reset(int val) {
        i = val;
    }

private:
    int i = 0;

    void sort_reverse(Node* node, std::vector<int>& v) {
        if (node == nullptr)
            return;
        sort_reverse(node->right, v);
        v.emplace_back(node->val);
        sort_reverse(node->left, v);
    }
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

void test_6() {
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
    print(bst.sort(root, false));
    print(bst.sort(root, true));
}

void test_7() {
    BST bst;
    Node* root = nullptr;
    root = bst.insert(root, 100);
    root = bst.insert(root, 50);
    root = bst.insert(root, 150);
    bst.bfs(root);
    printf("sum of all nodes == [%d]\n", bst.sum(root));
}

void test_8() {
    BST bst;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    bst.bfs(root);
    printf("sum of all nodes == [%d]\n", bst.sum(root));
}

void test_9() {
    BST bst;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(-3);
    bst.bfs(root);
    int res = INT_MIN;
    bst.largest_subtree_sum(root, res);
    printf("largest subtree sum == [%d]\n", res);
}

void test_10() {
    BST bst;
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    bst.bfs(root);
    printf("sum of tree         == [%d]\n", bst.sum(root));
    int res = INT_MIN;
    bst.largest_subtree_sum(root, res);
    printf("largest subtree sum == [%d]\n", res);
}

void test_11() {
    BST bst;
    Node* root = nullptr;
    root = bst.insert(root, 100);
    root = bst.insert(root, 50);
    root = bst.insert(root, 150);
    root = bst.insert(root, 25);
    bst.bfs(root);
    printf("sum of a level(%d) == [%d]\n", 25, bst.sum_of_level(root, 25));
    printf("sum of a level(%d) == [%d]\n", 26, bst.sum_of_level(root, 26));
    printf("sum of a level(%d) == [%d]\n", 200, bst.sum_of_level(root, 200));
    printf("sum of a level(%d) == [%d]\n", 150, bst.sum_of_level(root, 150));
}

void test_12() {
    BST bst;
    Node* root = nullptr;
    root = bst.insert(root, 100);
    root = bst.insert(root, 50);
    root = bst.insert(root, 150);
    root = bst.insert(root, 25);
    root = bst.insert(root, 10);
    root = bst.insert(root, 200);
    root = bst.insert(root, 250);
    root = bst.insert(root, 5);
    root = bst.insert(root, 1);
    bst.bfs(root);
    printf("minimum number == [%d]\n", bst.min(root));
    printf("maximum number == [%d]\n", bst.max(root));
}


int main() {
    //test_1();
    //test_2();
    //test_3();
    //test_4();
    //test_5();
    //test_6();
    //test_7();
    //test_8();
    //test_9();
    //test_10();
    //test_11();
    test_12();

    return 0;
}
