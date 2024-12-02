#include <stdio.h>
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

    if (arr[mid] == target) {
            return mid; 
        }

        if (arr[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return -1; 
}
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}