#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5+2;
int n; // Số lượng đỉnh của đồ thị
int d[maxN], par[maxN];
bool visited[maxN];
vector <int> g[maxN];

void bfs(int s) { // Với s là đỉnh xuất phát (đỉnh nguồn)
    fill_n(d, n + 1, 0);
    fill_n(par, n + 1, -1);
    fill_n(visited, n + 1, false);

    queue <int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!visited[v]) {
                d[v]     = d[u] + 1;
                par[v]   = u;
                visited[v] = true;
                q.push(v);
            }
        }
        if (!visited[u]) cout << "No path!";
        else {
            vector <int> path;
            for (int v = u; v != -1; v = par[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            
            cout << "Path: ";
            for (auto v : path) cout << v << ' ';
        }
    }
    
}


int main(){

    return 0;
}