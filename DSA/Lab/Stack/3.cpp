vector<int> nextGreater(vector<int>& arr){
    stack<int> st;
    int len = arr.size();
    vector<int> ans(len,-1);
    for(int i = 0 ;i<len;i++){
       while(!st.empty() && arr[st.top()] < arr[i]){
           ans[st.top()] = arr[i];
           st.pop();
       }
         st.push(i);
    }
    return ans;
}