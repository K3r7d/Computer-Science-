string removeDuplicates(string S){
    /*TODO*/
    stack<char> st;
    int len = S.size();
    string res = "";
    for(int i = 0;i<len;i++){
        if(st.empty()){
            st.push(S[i]);
        }
        else if(S[i] == st.top()){
            st.pop();
        }
        else{
            st.push(S[i]);
        }
    }
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    return res;
}