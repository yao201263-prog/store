#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>sticks(n);
    for(int i=0;i<n;i++)cin>>sticks[i];
    int length;cin>>length;
    sort(sticks.begin(),sticks.end());
    vector<int>dp(length+1,-1);
    dp[0]=0;//dp[i]means the ans of length =i;
    for(int i=1;i<=length;i++){
        for(int j=0;j<n;j++){
            if(i-sticks[j]>=0){
                if(dp[i-sticks[j]]!=-1){
                    if(dp[i]==-1){
                        dp[i]=dp[i-sticks[j]]+1;
                    }else{
                        dp[i]=min(dp[i],dp[i-sticks[j]]+1);
                    }
                }
            }
        }
    }
    cout<<dp[length]<<endl;
    return 0;
}

//14min