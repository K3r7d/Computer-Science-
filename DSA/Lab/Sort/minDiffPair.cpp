string minDiffPairs(int* arr, int n){
    // STUDENT ANSWER
    if(n==1) return "";
    stringstream s ;
    sort(arr, arr+n);
    int minDiff = INT32_MAX;
    
    for(int i = 1; i < n; i++){
        int dif = arr[i] - arr[i-1];
        if(dif < minDiff) minDiff = dif;
    }
    bool flag = false;
    for(int i = 1; i < n; i++){
        int dif = arr[i] - arr[i-1];
        if(dif == minDiff){
            if(flag) s<<", ";
            s << "(" << arr[i-1] << ", " << arr[i] << ")";
            flag = true;
        } 
    }
    return s.str();
}