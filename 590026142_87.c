#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            return mid; // element found
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; // not found
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Input (array must be sorted)
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("%d", result);  // index
    else
        printf("-1");

    return 0;
}