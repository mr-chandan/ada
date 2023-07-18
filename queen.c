#include<stdio.h>
#include <stdlib.h>

int a[30];
int count = 0;

int place(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        if ((a[j] == i) || (abs(a[j] - i) == abs(j - k))) {
            return 0;
        }
    }
    return 1;
}

void print_sol(int n) {
    count++;
    printf("\n\nSolution #%d:\n", count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void nQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            a[k] = i;
            if (k == n)
                print_sol(n);
            else
                nQueens(k + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);
    nQueens(1, n);
    printf("\nTotal solutions = %d\n", count);
    return 0;
}
