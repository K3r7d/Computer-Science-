bool canEatFood(int maze[5][5], int fx, int fy) {
    node mouse(0, 0);
    std::stack<node> path;
    path.push(mouse);

    while (!path.empty()) {
        node top = path.top();
        int i = top.x;
        int j = top.y;
        int d = top.dir;
        maze[i][j] = 2;
        if (i == fx && j == fy) {
            return true;
        }
        bool moved = false;
        for (int dir = d; dir < d + 4; dir++) {
            int ni, nj;
            if (dir % 4 == 0) {
                ni = i - 1;
                nj = j;
            } else if (dir % 4 == 1) {
                ni = i;
                nj = j + 1;
            } else if (dir % 4 == 2) {
                ni = i + 1;
                nj = j;
            } else {
                ni = i;
                nj = j - 1;
            }
            if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5 && maze[ni][nj] == 1) {
                node temp(ni, nj);
                temp.dir = dir + 1;
                path.push(temp);
                moved = true;
                break;
            }
        }
        if (!moved) {
            path.pop();
        }
    }
    return false;
}