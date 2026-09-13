#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rnk;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);   // 路径压缩
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    // 按秩合并：把秩小的树挂到秩大的树下
    if (rnk[x] < rnk[y])
        parent[x] = y;
    else {
        parent[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

int main() {
    int n, m, caseNum = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        parent.resize(n + 1);
        rnk.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            unite(a, b);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (find(i) == i) cnt++;

        cout << "Case " << caseNum++ << ": " << cnt << endl;
    }
    return 0;
}