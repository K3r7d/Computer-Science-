int secondsToBeRotten(vector<vector<int>>& grid) {
   int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0, time = -1;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2)
                q.push({i, j});
            else if (grid[i][j] == 1)
                ++fresh;
        }
    }
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            pair<int, int> cur = q.front(); q.pop();
            for (vector<int>& dir : dirs) {
                int x = cur.first + dir[0], y = cur.second + dir[1];
                if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 1)
                    continue;
                --fresh;
                grid[x][y] = 2;
                q.push({x, y});
            }
        }
        ++time;
    }
    return fresh == 0 ? max(0, time) : -1;
}