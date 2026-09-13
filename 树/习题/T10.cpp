#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>right(n);
        priority_queue<int,vector<int>,greater<int>>q;//最小堆
        for(int i=0;i<n;i++){
            cin>>right[i];
            q.push(right[i]);
        }

        int ans=0;
        while(q.size()>1){
            int a=q.top();q.pop();
            int b=q.top();q.pop();
            int c=a+b;ans+=c;
            q.push(c);
        }
        cout<<ans<<endl;
    }
    return 0;
}