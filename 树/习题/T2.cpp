#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int dfs(vector<int>&left,vector<int>&right,int idx){
    if(idx==-1){return 0;}
    int ldep=dfs(left,right,left[idx-1]);
    int rdep=dfs(left,right,right[idx-1]);
    return max(ldep,rdep)+1;
}

int main(){
    int n;cin>>n;
    vector<int>left(n);
    vector<int>right(n);
    for(int i=0;i<n;i++){
        cin>>left[i]>>right[i];
    }
    int dep=dfs(left,right,1);
    cout<<dep<<endl;
    return 0;
}