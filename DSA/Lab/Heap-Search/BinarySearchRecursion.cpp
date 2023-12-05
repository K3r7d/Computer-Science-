int binarySearch(int arr[], int left, int right, int x)
{
    if(left > right){
         return -1; 
    } 
    int index = left + (right - left) / 2;
    cout << "We traverse on index: " << index << endl;
    
    if(arr[index] > x) return binarySearch(arr, left, index - 1, x);
    if(arr[index] < x) return binarySearch(arr, index + 1, right, x);
    else return index;
}
