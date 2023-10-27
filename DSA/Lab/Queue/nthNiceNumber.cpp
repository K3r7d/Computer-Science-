long long nthNiceNumber(int n) {
    queue<long long> q;
    q.push(2);
    q.push(5);
    while (--n) {
        long long num = q.front();
        q.pop();
        q.push(num * 10 + 2);
        q.push(num * 10 + 5);
    }
    return q.front();
}
