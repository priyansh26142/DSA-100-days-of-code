#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int k;
    scanf("%d", &k);
    
    int comparisons = 0;
    int result = -1;
    
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            result = i;
            break;
        }
    }
    
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not Found\n");
    
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}