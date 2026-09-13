#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;cin>>N;
    vector<vector<int>>arr(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>dp(N,vector<int>(N));
    dp[0][0]=arr[0][0];
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){
           if(j==0){
                dp[i][j]=dp[i-1][j]+arr[i][j];
           }else if(j<i){
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+arr[i][j];
           }else{
                dp[i][j]=dp[i-1][j-1]+arr[i][j];
           }
        }
    }

    int maxval=0;
    for(int i=0;i<N;i++){
        if(maxval<dp[N-1][i]){
            maxval=dp[N-1][i];
        }else{
            continue;
        }
    }

    cout<<maxval<<endl;
    return 0;
}