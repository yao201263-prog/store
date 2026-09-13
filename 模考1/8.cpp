#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int N;cin>>N;
    while(N--){
        int L,A;
        cin>>L>>A;
        vector<int>p(L);
        for(int i=0;i<L;i++){
            cin>>p[i];
        }

        vector<int>dp(A+1,1000000);//面值为i的最小硬币数
        dp[0]=0;
        for(int i=1;i<=A;i++){
            for(int j=0;j<L;j++){
                if(i>=p[j]){
                    dp[i]=min(dp[i],dp[i-p[j]]+1);
                }
            }
        }
        if (dp[A] >= 1000000) cout << -1 << endl;
        else cout << dp[A] << endl;
    }
    return 0;
}