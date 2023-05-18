#include <stdio.h>

void bubblesort(int array[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int array[] = {64, 25, 12, 22, 11, 34, 100, 99, 44};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Array before sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    bubblesort(array, size);

    printf("\nArray after sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
