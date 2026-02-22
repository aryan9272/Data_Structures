#include <stdio.h>

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int i = lb + 1;
    int j = ub;
    int temp;
    while (1) {
        while (i <= ub && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else
            break;
    }
    temp = arr[lb];
    arr[lb] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int pi = partition(arr, lb, ub);
        quickSort(arr, lb, pi - 1);
        quickSort(arr, pi + 1, ub);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr1[n], arr2[n], arr3[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
    printf("\nOriginal Array:\n");
    displayArray(arr1, n);

    printf("Merge Sort \n");
    mergeSort(arr1, 0, n - 1);
    printf("Sorted Array: ");
    displayArray(arr1, n);

    printf("Quick Sort \n");
    quickSort(arr2, 0, n - 1);
    printf("Sorted Array: ");
    displayArray(arr2, n);

    printf("Heap Sort \n");
    heapSort(arr3, n);
    printf("Sorted Array: ");
    displayArray(arr3, n);

    return 0;
}
