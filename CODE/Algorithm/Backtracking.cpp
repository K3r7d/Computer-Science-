#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Permutatition{
    private:
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> visited;
    public:
        Permutatition(vector<int> nums){
            visited = vector<bool>(nums.size(),false);
            backtrack(nums,current,visited,ans);
        }

        vector<vector<int>> permute(vector<int>& nums) {
            vector<bool> visited(nums.size(), false);
            backtrack(nums, current, visited, ans);
            return ans;
        }
    private:
        void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& visited, vector<vector<int>>& ans) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                current.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, current, visited, ans);
                current.pop_back();
                visited[i] = false;
            }
        }
    }
};



int main(){
    vector<int> nums = {1,2,3};
    Permutatition p(nums);
    vector<vector<int>> ans = p.permute(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}