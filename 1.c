#include <stdio.h>
#include <conio.h>
#include <time.h>

void main()
{
    int arr[10], i, n, sum=0;
    clock_t start, end;
    double timetaken;
    start = clock();
    printf("enter the size of the array");
    scanf("%d", &n);

    printf("enter the array elements");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i <= n; i++)
    {
        sum = sum + arr[i];
    }

    printf("sum of array elements = %d\n", sum);
    end = clock();

    timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("time taken is  = %d", timetaken);
}