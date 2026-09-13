#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N;cin>>N;
    vector<int>q(N);
    for(int i=0;i<N;i++){
        cin>>q[i];
    }

    int dp[N];
    for(int i=0;i<N;i++){
        dp[i]=1;
    }

    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(q[i]>q[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    int ans=0;
    for(int i=0;i<N;i++){
        if(ans<dp[i]){
            ans=dp[i];
        }
    }

    cout<<ans<<endl;
    return 0;
}