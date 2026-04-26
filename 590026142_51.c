#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* ans = LCA(root, n1, n2);

    if (ans != NULL)
        printf("%d", ans->data);

    return 0;
}