#include<bits/stdc++.h>
using namespace std;
int maxvalue(vector<int>&tree,int idx){
    int n=tree.size();
    if(idx>=n)return 0;
    int l=2*idx+1,r=2*idx+2;
    int lv=maxvalue(tree,l),rv=maxvalue(tree,r);
    if(l>=n&&idx<n){//叶子
        return tree[idx];
    }

    //1不选根(选两个子树)
    int w1=lv+rv;
    //2选根(不能直接选子节点)
    int w2=maxvalue(tree,2*l+1)+maxvalue(tree,2*l+2)+
    maxvalue(tree,2*r+1)+maxvalue(tree,2*r+2)+tree[idx];

    return max(w1,w2);
}

int main(){
    int N;cin>>N;
    vector<int>tree(N);
    for(int i=0;i<N;i++)cin>>tree[i];
    int ans=maxvalue(tree,0);
    cout<<ans<<endl;
    return 0;
}

//20min