#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        int l1=s1.size();
        int l2=s2.size();
        string dp[l1][l2];
        //dp[i][j]代表分别以s1的前i+1个，s2前j+1个的最长子序列
        if(s1[0]==s2[0]){
            dp[0][0]=s1[0];
        }else{
            dp[0][0]="";
        }

        for(int i=1;i<l1;i++){
            if(s1[i]==s2[0]){
                dp[i][0]=s2[0];
            }else{ 
                dp[i][0]=dp[i-1][0];
               
            }
        }

        for(int i=1;i<l2;i++){
            if(s2[i]==s1[0]){
                dp[0][i]=s1[0];
            }else{
                dp[0][i]=dp[0][i-1];
            }
        }

        for(int i=1;i<l1;i++){
            for(int j=1;j<l2;j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i-1][j-1]+s1[i];
                }else{
                    dp[i][j]=(dp[i-1][j].size()>dp[i][j-1].size())?dp[i-1][j]:dp[i][j-1];
                }
            }
        }
        
        cout<<dp[l1-1][l2-1].size()<<endl;
    }
    return 0;
}