#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int dp[1005][1005];
int main(){
    int N;cin>>N;
    string s1,s2;
    while(N--){
        cin>>s1>>s2;
        int l1=s1.size();
        int l2=s2.size();
        //s1的前i个字符和s2的前j个字符的距离
        for (int i = 0; i <= l1; i++) dp[i][0] = i;
        for (int j = 0; j <= l2; j++) dp[0][j] = j;

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                }
            }
        }
        cout<<dp[l1][l2]<<endl;
    }
    return 0;
}