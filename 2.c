#include <stdio.h>
#include <conio.h>
#include <time.h>

void main()
{
    int  i, n, sum=0;
    clock_t start, end;
    double timetaken;
    start = clock();

    printf("enter the nth element");
    scanf("%d", &n);


    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    printf("sum of %d natural number = %d\n", n, sum);
    end = clock();

    timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("time taken is  = %d", timetaken);
}