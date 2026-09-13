#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n = 26) {  
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]); // 路径压缩
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if(rx == ry) return;
        if(rank[rx] < rank[ry]) parent[rx] = ry;
        else if(rank[rx] > rank[ry]) parent[ry] = rx;
        else { parent[ry] = rx; rank[rx]++; }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n;
    cin >> n;                    // 读入n
    vector<string> eqs;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;                // 读取n个字符串
        eqs.push_back(s);
    }

    DSU dsu(26);
    // 第一步：处理所有 == 关系
    for(const string& s : eqs) {
        if(s[1] == '=') {      
            int a = s[0] - 'a';
            int b = s[3] - 'a';
            dsu.unite(a, b);
        }
    }

    // 第二步：检查所有 != 关系是否矛盾
    for(const string& s : eqs) {
        if(s[1] == '!') {
            int a = s[0] - 'a';
            int b = s[3] - 'a';
            if(dsu.same(a, b)) {
                cout << "False" << endl;
                return 0;
            }
        }
    }

    cout << "True" << endl;
    return 0;
}