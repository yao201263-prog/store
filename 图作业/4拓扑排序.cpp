#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    vector<vector<int>> g;       // 邻接表
    vector<int> indeg;           // 入度
    vector<int> if_exist;        // 节点是否存在

    graph(int n) {
        g.resize(n);
        indeg.assign(n, 0);
        if_exist.assign(n, 1);
    }

    void insert(int x, int y) {
        g[x].push_back(y);
        indeg[y]++;
    }

    void gdelete(int x) {
        if (!if_exist[x]) return;
        for (int y : g[x]) {
            indeg[y]--;
        }
        g[x].clear();
        if_exist[x] = 0;
    }

    // 查找第一个入度为0且存在的节点
    int find_zero_indeg() {
        for (int i = 0; i < g.size(); i++) {
            if (if_exist[i] && indeg[i] == 0)
                return i;
        }
        return -1;
    }

    bool is_empty() {
        for (int x : if_exist)
            if (x) return false;
        return true;
    }
};

int main() {
    int v, a;
    cin >> v >> a;
    graph G(v);

    int x, y;
    for (int i = 0; i < a; i++) {
        cin >> x >> y;
        x--; y--;
        G.insert(x, y);
    }

    int first = 1;
    while (!G.is_empty()) {
        int m = G.find_zero_indeg();
        if (m == -1) {               
            cerr << "Graph has a cycle!" << endl;
            break;
        }
        if (!first) cout << " ";      
        cout << "v" << m + 1;
        first = 0;
        G.gdelete(m);
    }
    cout << endl;                    
    return 0;
}