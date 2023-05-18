#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    i = l;
    j = m + 1;
    k = l;

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            arr[k] = arr[i];
            i++;
        }
        else
        {
            arr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= m)
    {
        arr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        arr[k] = arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {10, 8, 7, 6, 5, 4, 3, 2, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted Array: ");
    printArray(arr, size);

    return 0;
}
