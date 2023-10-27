bool valid(char a, char b){
    if(a == '(' && b == ')') return true;
    if(a == '{' && b == '}') return true;
    if(a == '[' && b == ']') return true;
    return false;
}

bool isValidParentheses (string s){
    stack<char> st;
    int len = s.size();
    for(int i = 0;i< len;i++){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{') st.push(s[i]);
        else {
            if(st.empty()) return false; // Add this line
            else if(valid(st.top(), s[i])){
                st.pop();
            }
            else return false;
        }
    }
    if(!st.empty()) return false;
    return true;
}
