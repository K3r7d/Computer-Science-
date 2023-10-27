vector<int> stock_span(const vector<int>& ns) {
    // STUDENT ANSWER
    vector<int> ans;
    stack<int> s1;
    stack<int> s2;
    ans.push_back(1);
    s1.push(ns[0]);
    int len = ns.size();
    for(int i = 1 ;i< len;i++){
        int count = 1;
        while(!s1.empty() && ns[i] > s1.top()){
            count++;
            s2.push(s1.top());
            s1.pop();
        }
        ans.push_back(count);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(ns[i]);
    }
    return ans;
}
