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

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n) {
            curr->left = createNode(arr[i++]);
            queue[rear++] = curr->left;
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            queue[rear++] = curr->right;
        }
    }
    return root;
}

int isComplete(struct Node* root) {
    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int flag = 0;

    while (front < rear) {
        struct Node* curr = queue[front++];

        if (curr == NULL) {
            flag = 1;
        } else {
            if (flag) return 0;
            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
    }
    return 1;
}

int isHeap(struct Node* root) {
    if (root == NULL) return 1;

    if (root->left && root->data > root->left->data)
        return 0;

    if (root->right && root->data > root->right->data)
        return 0;

    return isHeap(root->left) && isHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isComplete(root) && isHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}