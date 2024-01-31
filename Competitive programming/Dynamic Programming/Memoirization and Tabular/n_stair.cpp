#include<iostream>
#include<vector>

using namespace std;



int climbStairs(int n, unordered_map<int, int> &memo){
    if(n == 1 || n == 0){
        return 1;
    }
    if(memo.find(n) != memo.end()){
        return memo[n];
    }
    else{
        int ans = climbStairs(n-1, memo) + climbStairs(n-2, memo);
        memo[n] = ans;
        return ans;
    
}

int climbStairs(int n){
    unordered_map<int, int> memo;
    return climbStairs(n, memo);
}