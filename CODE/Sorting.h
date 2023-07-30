#ifndef SORTING_H
#define SORTING_H

#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
using namespace std::chrono;
void swap(int* x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
};

void InsertionSort(vector<int> &arr){
    for(int i = 2;i<=arr.size();i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void DecreasingInsertionSort(vector<int> &arr){
    for(int i = 1;i<arr.size();i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]<key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void Merge(vector<int> &arr, int l,int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i = 0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int i = 0;i<n2;i++){
        R[i] = arr[m+1+i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int> &arr,int l,int r){
    if(l<r){
        int m = (l+r)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}

int randomNumber(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    int random = dis(gen);
    return random;
}

void SelectionSort(vector<int> &arr){
    for(int i = 0;i<arr.size()-1;i++){
        int min = i;
        for(int j = i+1;j<arr.size();j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
}

void BubbleSort(vector<int> &arr){
    for(int i = 0;i<arr.size()-1;i++){
        for(int j = 0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void PermutationSort(vector<int> &arr){
    for(int i = 0;i<arr.size()-1;i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
    
void Heapify(vector<int> &arr,int n,int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        Heapify(arr,n,largest);
    }
}

#endif