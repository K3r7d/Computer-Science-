int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    deque<int> q;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        while (!q.empty() && nums[i] > nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
        if (q.front() == i - k) {
            q.pop_front();
        }
        if (i >= k - 1) {
            sum += nums[q.front()];
        }
    }
    return sum;
}