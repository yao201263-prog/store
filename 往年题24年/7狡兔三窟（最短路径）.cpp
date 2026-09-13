#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;

    vector<int> dist(n + 1, -1);
    queue<int> q;
    // 三个出口作为源点
    dist[c1] = 0; q.push(c1);
    dist[c2] = 0; q.push(c2);
    dist[c3] = 0; q.push(c3);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == -1) cout << -1 << '\n';
        else cout << dist[i] + 1 << '\n';
    }
    return 0;
}