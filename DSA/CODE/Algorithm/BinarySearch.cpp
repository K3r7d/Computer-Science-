#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int> nums, int target){
    int left = 0;
    int right = nums.size()-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid+1;
        else right = mid-1;
    }
    return -1;
}


int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int target = 5;
    
    cout<<"The index of "<<target<<" is: ";
    cout<<binarySearch(nums,target);

    //STL
    auto low = upper_bound(nums.begin(),nums.end(),target);
    auto high = lower_bound(nums.begin(),nums.end(),target);
    cout<<"\nSTL: "<< low - nums.begin() <<" "<<high - nums.begin();


    return 0;
}