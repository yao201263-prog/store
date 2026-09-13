#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;


void postorder(int u, const vector<vector<int>>& children, const vector<char>& nodes, string& out) {
    for (int v : children[u]) {
        postorder(v, children, nodes, out);
    }
    out += nodes[u];
    out += ' ';   
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    string result;
    for (int t = 0; t < n; ++t) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<char> nodes;
        vector<int> degs;
        char ch;
        int d;
        while (ss >> ch >> d) {
            nodes.push_back(ch);
            degs.push_back(d);
        }
        if (nodes.empty()) continue;   
        int m = nodes.size();
        vector<vector<int>> children(m);
        queue<int> q;
        q.push(0);
        int idx = 1;   
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int degree = degs[u];
            for (int i = 0; i < degree; ++i) {
                if (idx >= m) break;   
                int child = idx++;
                children[u].push_back(child);
                q.push(child);
            }
        }
        postorder(0, children, nodes, result);
    }
    cout << result << endl;
    return 0;
}