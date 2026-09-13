#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> parent(N + 1);
    vector<vector<int>> children(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> parent[i];
        if (parent[i] != -1) {
            children[parent[i]].push_back(i);
        }
    }
    vector<int> depth(N + 1, 0);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : children[u]) {
            depth[v] = depth[u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << depth[i] << endl;
    }
    return 0;
}