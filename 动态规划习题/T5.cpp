#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int n;cin>>n;
    vector<vector<int>>dp(n,vector<int>(n));//dp[i][j]表示i+1被拆成j+1份的最大积
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        dp[i][0]=i+1;
        dp[i][i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<i;j++){
            int max_val=1;
            for(int m=i+1-j;m>=1;m--){
                int val=dp[i-m][j-1]*m;
                max_val=max(max_val,val);
            }
            dp[i][j]=max_val;
        }
    }

    int ans=0;
    for(int i=1;i<n;i++){
        ans=max(ans,dp[n-1][i]);
    }
    cout<<ans<<endl;
    return 0;
}