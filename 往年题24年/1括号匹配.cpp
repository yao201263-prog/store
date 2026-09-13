#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;string s;
    while(cin>>n>>s){
        stack<int>st;
        bool flg=1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){st.push(i+1);}
            if(s[i]=='2'){
                int x=st.top();
                cout<<((flg)?"":" ")<<x;
                flg=0;
                st.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}