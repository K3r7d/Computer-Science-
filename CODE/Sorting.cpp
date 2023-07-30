#include"Sorting.h"

int main(){
    
    //input//
    vector<int> arr;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    for(int i = 0;i<n;i++){
        int temp = rand()%100;
        arr.push_back(temp);
    }
    //-----------------------------------------------------------//

    //Choose type of sorting//
        cout<<"Choose the type of sorting: "<<endl; 
        cout<<"1. Insertion sort"<<endl;
        cout<<"2. Merge sort"<<endl;
        cout<<"3. Selection sort"<<endl;
        cout<<"4. Bubble sort"<<endl;  
        cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    
    //Start sorting//
    auto start = high_resolution_clock::now();
        if(choice == 1) 
        DecreasingInsertionSort(arr);
        if(choice == 2)
        MergeSort(arr,0,arr.size()-1);
        if(choice == 3)
        SelectionSort(arr);
        if(choice == 4)
        BubbleSort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    //-----------------------------------------------------------//


    //output//
    cout<<"which one do you want to print?: \n1. Sorted array\n2. Execution time\n";
    cin>>choice;
    if(choice == 1){
        for(int i = 0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
    }
    
    //Execution time//
    else if(choice == 2)
    cout << "\nExecution time: " << duration.count() << " milliseconds" << endl;
    //-----------------------------------------------------------//
    return 0;
}