#include <stdio.h>
#include <time.h>

int gcd(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return gcd(num2, num1 % num2);
    }
}

void main()
{
    int num1, num2;
    clock_t start, end;
    double time_taken;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    start = clock();

    int result = gcd(num1, num2);

    printf("The GCD of %d and %d is %d\n", num1, num2, result);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to compute GCD: %f seconds\n", time_taken);
}
