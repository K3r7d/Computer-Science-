#include<iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int* arr, int n, int& swp, int& com){
    for(int i = 0;i<n-1;i++){
        int min_idx = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]< arr[min_idx]){
                min_idx = j;
            }
            com++;
        }
        if(min_idx != i){
            swap(arr[i],arr[min_idx]);
            swp++;
        }
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
    int swap_time = 0;
    int compare_time = 0;
    SelectionSort(arr, n,swap_time,compare_time);
    cout << "Sorted array: ";
    print(arr, n);
    cout <<"swap: "<<swap_time;
    cout << endl;
    cout <<"compare: "<<compare_time;
    cout << endl;
    return 0;
}