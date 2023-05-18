#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    for (int i = low; i <= high; i++) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int array[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(array) / sizeof(array[0]);
    int target_number = 7;

    int result = binary_search(array, size, target_number);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}
