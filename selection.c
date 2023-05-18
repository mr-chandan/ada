#include <stdio.h>

void selectionSort(int array[], int size)
{
	int i, j, small, temp;

	for (i = 0; i < size - 1; i++)
	{
		small = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[small])
			{
				small = j;
			}
		}

		if (small != i)
		{
			temp = array[i];
			array[i] = array[small];
			array[small] = temp;
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

	selectionSort(array, size);

	printf("\nArray after sorting: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
