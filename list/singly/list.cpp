/*
  Rakesh Kumar
  Never stop learning
  24/05/2021
 */

#include <bits/stdc++.h>

struct Node {
    Node() {}
    Node(int val) : val(val) {}

    int val = 0;
    Node* next = nullptr;
};

Node* push_back(Node* head, int val) {
    if (head == nullptr)
        head = new Node(val);
    else {
        Node* node = head;
        while (node->next)
            node = node->next;
        node->next = new Node(val);
    }
    return head;
}

void traverse(Node* head) {
    printf("----------------------------------------------------------\n");
    Node* node = head;
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n----------------------------------------------------------\n");
}

Node* merge(Node* a, Node* b) {
    Node* res = nullptr;
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;
    if (a->val < b->val) {
        res = a;
        res->next = merge(a->next, b);
    } else {
        res = b;
        res->next = merge(a, b->next);
    }
    return res;
}

int main() {
    Node* head1 = nullptr;
    for (int i = 1; i <= 20; i += 2)
        head1 = push_back(head1, i);
    traverse(head1);

    Node* head2 = nullptr;
    for (int i = 2; i <= 20; i += 2)
        head2 = push_back(head2, i);
    traverse(head2);
    Node* head3 = merge(head1, head2);
    traverse(head3);

    return 0;
}
