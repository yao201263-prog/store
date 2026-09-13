#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s; int l=s.size();
    vector<int>dep(l);
    for(int i=0;i<l;i++){
        int d=1;
        for(int j=0;j<i;j++){
            if(s[j]=='(')d++;
            if(s[j]==')')d--;
        }
        dep[i]=d;
    }
    int k;cin>>k;
    int ans=0;
    for(int i=0;i<l;i++){
        if(dep[i]==k&&s[i]!=','&&s[i]!='('&&s[i]!=')')ans++;
    }
    cout<<ans<<endl;
    return 0;
}
