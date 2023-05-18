#include <stdio.h>

int linearSearch(int array[], int size, int key)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);
    int key = 22;

    int result = linearSearch(array, size, key);

    if (result != -1)
    {
        printf("Element %d found at index %d.\n", key, result);
    }
    else
    {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
