#include<iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void InsertionSort(int* arr, int n,int& swp,int& com)
{
    // int i, key, j;
    // for (i = 1; i < n; i++) {
    //     key = arr[i];
    //     j = i - 1;

    //     while (j >= 0 && arr[j] > key) {
    //         arr[j + 1] = arr[j];
    //         j = j - 1;
    //     }
    //     arr[j + 1] = key;
    // }
    for(int i = 1;i<n;i++){
        for(int j = i;j>0 && arr[j]<arr[j-1];j--){
            swap(arr[j],arr[j-1]);
            swp++;
            com++;
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
    InsertionSort(arr, n,swap_time,compare_time);
    cout << "Sorted array: ";
    print(arr, n);
    cout <<"swap: "<<swap_time;
    cout << endl;
    cout <<"compare: "<<compare_time;
    cout << endl;
    return 0;
}