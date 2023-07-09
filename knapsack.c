#include <stdio.h>

int main() {
    int n = 5;
    int weight[n], prize[n];
    float ratio[n];
    int capacity = 4, tp = 0, ip;
    float x[n];

    printf("Enter weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter prizes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &prize[i]);
    }

    for (int i = 0; i < n; i++) {
        ratio[i] = ( weight[i] / prize[i]);  // Calculate the weight-to-prize ratio
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] > ratio[j + 1]) {
                // Swap ratio
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                // Swap weight
                int tempw = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempw;

                // Swap prize
                int tempp = prize[j];
                prize[j] = prize[j + 1];
                prize[j + 1] = tempp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        x[i] = 0.0;  // Initialize x array with zeros
    }

    for (ip = 0; ip < n; ip++) {
        if (weight[ip] > capacity) {
            break;
        } else {
            x[ip] = 1.0;
            tp += prize[ip];
            capacity -= weight[ip];
        }
    }

    if (ip < n) {
        x[ip] = (float) capacity / weight[ip];
    }

    tp += x[ip] * prize[ip];

    printf("Fractional knapsack solution:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, x[i]);
    }

    printf("Total prize: %d\n", tp);

    return 0;
}
