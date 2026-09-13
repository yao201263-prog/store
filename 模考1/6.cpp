#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct DSU{
    vector<int>parent,rnk;
    DSU(int n){
        parent.resize(n+1);
        rnk.resize(n+1);
        for(int i=1;i<n+1;i++){
            parent[i]=i;
            rnk[i]=0;
        }
    }

    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int a,int b){
        a=find(a);b=find(b);
        if(a==b)return 0;
        if(rnk[a]<rnk[b]){
            swap(a,b);
        }
        parent[b]=a;
        if(rnk[b]==rnk[a])rnk[a]++;
        return 1;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;cin>>k;
    while(k--){
        int n,m;cin>>n>>m;
        DSU dsu(n);
        vector<int>deg(n+1,0);
        bool ok=1;
        for(int i=0;i<m;i++){
            int a,b;cin>>a>>b;
            if(!ok)continue;
            deg[a]++;deg[b]++;
            if(deg[a]>2||deg[b]>2){
                ok=0;
            }

            if(!dsu.unite(a,b)){
                ok=0;
            }
        }
        cout<<((ok)?"Yes":"No")<<endl;
    }
    return 0;
}