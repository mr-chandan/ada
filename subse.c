#include <stdio.h>

int set[10], subset[10], targetSum;

void generateSubsets(int currentSum, int start, int end)
{
    if (currentSum == targetSum)
    {
        printf("Subset: ");
        for (int i = 0; i < end; i++)
        {
            if (subset[i] == 1)
            {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i < end; i++)
        {
            if (currentSum + set[i] <= targetSum)
            {
                subset[i] = 1;
                generateSubsets(currentSum + set[i], i + 1, end);
                subset[i] = 0;
            }
        }
    }
}

void main()
{
    int n, sum = 0;

    printf("Enter the size of the set: ");
    scanf("%d", &n);

    printf("Enter the set in increasing order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    for (int i = 0; i < n; i++)
    {
        sum += set[i];
    }

    if (sum < targetSum || set[0] > targetSum)
    {
        printf("No subset possible.\n");
    }
    else
    {
        generateSubsets(0, 0, n);
    }
}