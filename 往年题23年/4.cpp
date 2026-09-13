#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main(){
    int N;cin>>N;
    vector<vi>graph(N,vi(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>graph[i][j];
        }
    }
    //最小生成树
    int total=0;
    vector<bool> visited(N, false);
    vector<int> minDist(N, INT_MAX);
    for (int k=0;k<N;++k) {
        // 选未访问中 minDist 最小的顶点
        int u=-1;
        for(int i=0;i<N;++i)
            if(!visited[i] && (u==-1||minDist[i]<minDist[u]))
                u = i;
        visited[u]=true;
        total+=minDist[u];

        // 更新邻接点
        for(int v=0;v<N;++v)
            if(!visited[v]&&graph[u][v]<minDist[v])
                minDist[v]=graph[u][v];
    }

    cout<<total<< endl;
    return 0;
}