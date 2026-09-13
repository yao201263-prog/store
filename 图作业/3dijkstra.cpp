#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9;
void find_path(vector<vector<pii>>&g,
    vector<string>&names,int id1,int id2){
    int n = g.size();
    vector<int> dist(n, INF);
    vector<int> pre(n, -1);
    vector<int> pre_w(n, 0);
    dist[id1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, id1});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        if (u == id2) break;
        for (auto& e : g[u]) {
            int w = e.first, v = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
                pre_w[v] = w;
                pq.push({dist[v], v});
            }
        }
    }

    if (id1 == id2) {
        cout << names[id1] << endl;
        return;
    }

    vector<int> path;
    int cur = id2;
    while (cur != -1) {
        path.push_back(cur);
        cur = pre[cur];
    }
    reverse(path.begin(), path.end());

    cout << names[path[0]];
    for (size_t i = 1; i < path.size(); ++i) {
        cout << "->(" << pre_w[path[i]] << ")->" << names[path[i]];
    }
    cout << endl;

}

int main(){
    int P;cin>>P;
    vector<vector<pii>>g(P);//(权，序号)
    unordered_map<string,int>h;
    vector<string>names(P);
    for(int i=0;i<P;i++){
        string s;cin>>s;
        names[i]=s;
        h.insert({s,i});
    }

    int Q;cin>>Q;
    for(int i=0;i<Q;i++){
        string s1,s2;
        cin>>s1>>s2;
        int w;cin>>w;
        int id1=h[s1];
        int id2=h[s2];
        g[id1].push_back({w,id2});
        g[id2].push_back({w,id1});
    }

    int R;cin>>R;
    for(int i=0;i<R;i++){
        string s1,s2;cin>>s1>>s2;
        int id1=h[s1];
        int id2=h[s2];
        find_path(g,names,id1,id2);
    }
    return 0;
}