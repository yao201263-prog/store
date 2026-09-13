#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rel;   // rel[x] 表示 x 与父节点的关系，0同1异

int find(int x) {
    if (parent[x] != x) {
        int root = find(parent[x]);
        rel[x] ^= rel[parent[x]];   // 路径压缩时更新与根的关系
        parent[x] = root;
    }
    return parent[x];
}

void unite(int x, int y, int d) {
    // d=1 表示 x 与 y 不同团伙
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    // 将 rx 挂到 ry 下，计算 rel[rx]
    parent[rx] = ry;
    rel[rx] = rel[x] ^ rel[y] ^ d;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        parent.resize(n + 1);
        rel.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;

        for (int i = 0; i < m; ++i) {
            char op;
            int a, b;
            cin >> op >> a >> b;
            if (op == 'A') {
                if (find(a) != find(b))
                    cout << "Not sure yet." << endl;
                else {
                    if ((rel[a] ^ rel[b]) == 0)
                        cout << "In the same gang." << endl;
                    else
                        cout << "In different gangs." << endl;
                }
            } else { // 'D'
                unite(a, b, 1);   // 1 表示不同团伙
            }
        }
    }
    return 0;
}