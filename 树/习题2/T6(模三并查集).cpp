#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rel, rnk;

int find(int x) {
    if (parent[x] != x) {
        int root = find(parent[x]);
        rel[x] = (rel[x] + rel[parent[x]]) % 3;
        parent[x] = root;
    }
    return parent[x];
}

bool unite(int x, int y, int d) {
    // d: 1-同类, 2-X吃Y
    int wanted = d - 1;  // 同类->0, 吃->1
    int rx = find(x), ry = find(y);
    if (rx == ry) {
        // 检查是否冲突
        return ((rel[x] - rel[y] + 3) % 3) == wanted;
    }
    // 按秩合并
    if (rnk[rx] < rnk[ry]) {
        parent[rx] = ry;
        // 计算 rel[rx] 使得 x 与 y 关系正确
        // rel[x] + rel[rx] - rel[y] ≡ wanted (mod 3)
        rel[rx] = (rel[y] - rel[x] + wanted + 3) % 3;
    } else {
        parent[ry] = rx;
        rel[ry] = (rel[x] - rel[y] - wanted + 6) % 3; // 等价推导
        if (rnk[rx] == rnk[ry]) rnk[rx]++;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    parent.resize(n + 1);
    rel.assign(n + 1, 0);
    rnk.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) parent[i] = i;

    int fake = 0;
    for (int i = 0; i < k; ++i) {
        int d, x, y;
        cin >> d >> x >> y;
        // 边界条件检查
        if (x > n || y > n || (d == 2 && x == y)) {
            fake++;
            continue;
        }
        if (!unite(x, y, d)) {
            fake++;
        }
    }
    cout << fake << endl;
    return 0;
}