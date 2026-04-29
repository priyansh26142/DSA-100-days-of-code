#include <stdio.h>

int integerSqrt(int n) {
    int left = 0, right = n;
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        // Use long long to prevent overflow
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        }
        else if (square < n) {
            ans = mid;      // possible answer
            left = mid + 1; // try bigger
        }
        else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", integerSqrt(n));

    return 0;
}