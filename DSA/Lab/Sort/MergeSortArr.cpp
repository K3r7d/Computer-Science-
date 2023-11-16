
static void merge(T* left, T* middle, T* right){
    int const sub1 = middle - left + 1;
    int const sub2 = right - middle;
    
    auto leftArr = new T[sub1];
    auto rightArr = new T[sub2];
    
    for(auto i = 0; i < sub1; i++)
        leftArr[i] = left[i];
    for(auto j = 0; j < sub2; j++)
        rightArr[j] = middle[1 + j];
    
    int i = 0, j = 0, k = 0;
    
    while(i < sub1 && j < sub2){
        if(leftArr[i] <= rightArr[j]){
            left[k] = leftArr[i];
            i++;
        } else {
            left[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while(i < sub1){
        left[k] = leftArr[i];
        i++;
        k++;
    }
    
    while(j < sub2){
        left[k] = rightArr[j];
        j++;
        k++;
    }
    
    delete[] leftArr;
    delete[] rightArr;
    
    Sorting::printArray(left, right);
}

static void mergeSort(T* start, T* end){
    if(start < end){
        auto mid = start + (end - start) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}
