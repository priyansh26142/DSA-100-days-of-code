#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];

void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = -1;
}

void insert(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }
}

int search(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;
        if (table[index] == -1)
            return 0;
        if (table[index] == key)
            return 1;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    init(m);

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}