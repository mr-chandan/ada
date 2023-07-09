#include <stdio.h>
#include <time.h>

int main()
{
    int size, find;
    clock_t start, end;
    double timeused;

    start = clock();
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to be found: ");
    scanf("%d", &find);

    int low = 0;
    int high = size - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == find)
        {
            result = mid;
            break;
        }
        else if (arr[mid] < find)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array.\n");

    end = clock();
    timeused = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used: %f seconds\n", timeused);
}
