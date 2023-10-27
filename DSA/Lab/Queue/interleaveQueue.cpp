void interleaveQueue(queue<int>& q){
    int len = q.size();
    queue<int> q1;
    queue<int> q2;
    for(int i = 0;i<len/2;i++){
        q1.push(q.front());
        q.pop();
    }
    for(int i = 0;i<len/2;i++){
        q2.push(q.front());
        q.pop();
    }
    for(int i = 0;i<len/2;i++){
        q.push(q1.front());
        q.push(q2.front());
        q1.pop();
        q2.pop();
    }
}