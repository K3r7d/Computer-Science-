#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void BubbleSort(int* arr, int n,int &swap_time,int &compare_time) {
    bool swapped;
    for(int i = 1;i<n;i++){
        swapped = false;
        for(int j = 0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped =true;
                swap_time++;
            }
            compare_time++;
        }
            if(!swapped) break;
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
    BubbleSort(arr, n,swap_time,compare_time);
    cout << "Sorted array: ";
    print(arr, n);
    cout <<"swap: "<<swap_time;
    cout << endl;
    cout <<"compare: "<<compare_time;
    cout << endl;
    return 0;
}
