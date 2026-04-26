#include <stdio.h>
#include <stdlib.h>

/* Stack structure */
typedef struct Stack {
    int* arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int n) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = n;
    s->top = -1;
    s->arr = (int*)malloc(n * sizeof(int));
    return s;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int x) {
    s->arr[++(s->top)] = x;
}

int pop(Stack* s) {
    return s->arr[(s->top)--];
}

/* Main logic */
int main() {
    int N;
    scanf("%d", &N);

    int* queue = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &queue[i]);
    }

    Stack* s = createStack(N);

    /* Step 1: Push all queue elements into stack */
    for (int i = 0; i < N; i++) {
        push(s, queue[i]);
    }

    /* Step 2: Pop back to queue (reversed order) */
    for (int i = 0; i < N; i++) {
        queue[i] = pop(s);
    }

    /* Print reversed queue */
    for (int i = 0; i < N; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}