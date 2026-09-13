#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,M;
    while(cin>>n>>M&&n!=0){
        vector<vector<int>>graph(n);
        vector<int>degree(n);
        int a,b;
        for(int i=0;i<M;i++){
            cin>>a>>b;
            a--;b--;
            graph[a].push_back(b);degree[a]++;
            graph[b].push_back(a);degree[b]++;
        }

        vector<int>visited(n,0);
        queue<int>q;
        q.push(0);visited[0]=1;
        while(!q.empty()){
            int f=q.front();
            for(int i=0;i<graph[f].size();i++){
                int x=graph[f][i];
                if(!visited[x]){
                    q.push(x);
                    visited[x]=1;
                }
            }
            q.pop();
        }

        bool flag1=1;
        for(int x:visited){
            if(x==0){
                flag1=0;break;
            }
        }

        bool flag2=1;
        for(int x:degree){
            if(x%2!=0){
                flag2=0;break;
            }
        }

        cout<<((flag1&&flag2)?1:0)<<endl;
    }
    return 0;
}

