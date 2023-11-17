#include<vector>
struct Element{
    int val;
    int freq;
    int index;
};

bool compare(const Element &a, const Element &b){
    if(a.freq == b.freq) return a.index < b.index;
    return a.freq>b.freq;
}

void sortByFrequency(int arr[], int n){
    vector<Element> e;
    for(int i = 0;i<n;i++){
    bool flag = false;
        for(auto& element:e){
            if(arr[i] == element.val){
                element.freq++;
                flag = true;
                break;
            }
        }
        if(!flag) e.push_back({arr[i], 1, i});
    }
    sort(e.begin(),e.end(),compare);
    
    int index = 0;
    
    for(const auto& element: e)
        for(int i = 0; i<element.freq;i++)
            arr[index++] = element.val;
    
    
}