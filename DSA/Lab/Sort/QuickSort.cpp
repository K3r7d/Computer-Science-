
static void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}


static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearranging the array.
    const T pivot = *start;
    T *j = end;  // Increment j to avoid underflow in the loop
    T *i = start;
    do {
        do i++; while (*i < pivot);
        do j--; while (*j > pivot);
        if (i < j) {
            swap(i, j);
        }
    } while (i < j);
    swap(start, j);
    return j;
}


static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of the pivot in the subarray after every time calling the method Partition.
    if (start < end) {
        T* pivotPos = Partition(start, end);
        cout << (pivotPos - start) << " ";
        QuickSort(start, pivotPos);
        QuickSort(pivotPos + 1, end);
    }
}
