#include<iostream>
#include<vector>

using namespace std;

vector<int> memo(1000, -1);

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    int ans = fib(n-1) + fib(n-2);
    memo[n] = ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}