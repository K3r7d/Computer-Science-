template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int n = end-start;
    for(int i = 0;i<n-1;i++){
        int low_index = i;
        for(int j = i+1;j<n;j++)
            if(start[j]<start[low_index])
                low_index = j;
        swap(start[i],start[low_index]);
        printArray(start, end);
    }
}
