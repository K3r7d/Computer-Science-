int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos = left + ((x - arr[left]) * (right - left)) / (arr[right] - arr[left]);
    if(left<=right && x>= arr[left] && x<= arr[right]){
    cout<<"We traverse on index: "<<pos<<endl;
    if(arr[pos] == x) return pos;
    else if(arr[pos] < x) return interpolationSearch(arr, pos+1, right, x);
    else return interpolationSearch(arr, left, pos, x);
    }
    return -1;
}
