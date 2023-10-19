#include <iostream>

using namespace std;

void merge(int* arr, int const left, int const mid, int const right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void MergeSort(int* arr, int begin, int end) {
    if (begin < end) {
        int mid = begin + (end - begin) / 2;
        MergeSort(arr, begin, mid);
        MergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {9, 3, 4, 8, 2, 1, 7, 6, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    print(arr, n);

    return 0;
}
