#include <stdio.h>

int partition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int start = low;
  int end = high;

  while (start < end)
  {
    while (arr[start] <= pivot)
    {
      start++;
    }

    while (arr[end] > pivot)
    {
      end--;
    }

    if (start < end)
    {
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
    }
  }

  int temp = arr[low];
  arr[low] = arr[end];
  arr[end] = temp;

  return end;
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

int main()
{
  int arr[] = {10, 7, 8, 9, 1, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  quickSort(arr, 0, size - 1);

  printf("Sorted array: ");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  return 0;
}
