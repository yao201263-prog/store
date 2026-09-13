#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        string s;cin>>s;
        stack<int>st;
        
        bool flg=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                st.push(i+1);
            }else{
                int x=st.top();
                cout<<((flg)?" ":"")<<x;
                st.pop();
                flg=1;
            }
        }
        cout<<endl;
    }
    return 0;
}