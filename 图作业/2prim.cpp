#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n;cin>>n;
    vector<vector<pii>>g(n);//(权，顶点)
    vector<int>deg(n);
    for(int i=0;i<n;i++){
        char c;cin>>c;
        int x=c-'A';
        int t;cin>>t;
        deg[x]=t;
        for(int j=0;j<t;j++){
            char cc;cin>>cc;
            int y=cc-'A';
            int w;cin>>w;
            g[x].push_back({w,y});
            g[y].push_back({w,x});
        }
    }

    vector<int>inMST(n,0);
    vector<int>parent(n,-1);
    vector<int>dist(n,INT_MAX);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dist[0]=0;
    pq.push({0,0});

    while(!pq.empty()){
        int u=pq.top().second;//当前节点
        int w=pq.top().first;
        pq.pop();
        if(inMST[u])continue;
        inMST[u]=1;

        for(auto &e:g[u]){
            int v=e.second;
            int weight=e.first;
            if(!inMST[v]&&dist[v]>weight){
                parent[v]=u;
                dist[v]=weight;
                pq.push({weight,v});
            }
        }
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=dist[i];
    }
    cout<<sum<<endl;
    return 0;
}