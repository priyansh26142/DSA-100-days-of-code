#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }

    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main() {
    int n, m, i, x;

    scanf("%d", &n);
    struct Node *head1 = NULL, *temp = NULL;

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (head1 == NULL) {
            head1 = newNode;
            temp = head1;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &m);
    struct Node *head2 = NULL;
    temp = NULL;

    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (head2 == NULL) {
            head2 = newNode;
            temp = head2;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection\n");
    else
        printf("%d\n", result);

    return 0;
}