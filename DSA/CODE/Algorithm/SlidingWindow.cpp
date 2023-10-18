#include<iostream>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    vector<int> result;
    deque<int> dq;
    for(int i = 0;i<nums.size();i++){
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int SlidingWindownCount(vector<int>& nums, int k){
    int left = 0;
    int right = 1;
    int sum = nums[0];
    int count = 0;
    int len = nums.size();
    if (len == 1 && nums[0] == k)return 1;
    if (len == 1) return 0;
    if (nums[1] == k) count++;
    while(right<len){
        sum += nums[right];
        if (sum == k) count++;
        if (sum > k){
            while(sum > k){
                sum -= nums[left];
                left++;
            }
            if (sum == k) count++;
        }
        right++; 
    }
    return count;
}

int main(){
    vector<int> unsorted_arr = {1,3,-1,-3,5,3,6,7};
    vector<int> sorted_arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;
    
    
    cout<<"Sliding Window Count: ";
    cout<<SlidingWindownCount(sorted_arr, k)<<endl;


    vector<int> msd = maxSlidingWindow(unsorted_arr,k);
    cout<<"Max Sliding Window Array: ";
    for(int i = 0;i<unsorted_arr.size()-k+1;i++){
        cout<<msd[i]<<" ";
    }
    return 0;
}