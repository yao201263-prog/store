#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int main(){
    int n;cin>>n;
    int l;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<n;i++){
        cin>>l;
        q.push(l);
    }
    long long ans=0;
    while(q.size()>1){
        int a=q.top();q.pop();
        int b=q.top();q.pop();
        int c=a+b;ans+=c;
        q.push(c);
    }
    cout<<ans<<endl;
    return 0;
}