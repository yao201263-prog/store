#include<bits/stdc++.h>
using namespace std;
bool fs(string s){
    vector<int>times(26,0);
    vector<bool>visited(26,0);
    for(char c:s){
        times[c-'a']++;
    }
    int x=0;
    for(char c:s){
        if(times[c-'a']>=2&&!visited[c-'a']){
            x++;
            visited[c-'a']=1;
        }
    }
    return x>=2;
}
int main(){
    string s;cin>>s;
    int n=s.size();
    int k;cin>>k;
    int ans=0;
    for(int i=0;i<=n-k;i++){
        if(fs(s.substr(i,k))){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

//花了20分钟以上！