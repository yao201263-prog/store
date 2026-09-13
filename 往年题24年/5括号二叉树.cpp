#include <bits/stdc++.h>
using namespace std;
vector<int> get_depth(string&s){
    int n=s.size();
    vector<int>depth(n,-1);
    int dep=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(')dep++;
        if(s[i]==')')dep--;
        if(isupper(s[i])||s[i]=='*')depth[i]=dep;
    }
    return depth;
}

void pre_order(string&s){
    for(char c:s){
        if(isupper(c)){
            cout<<c;
        }
    }
    cout<<endl;
}

void in_order(string&s){
    int n=s.size();
    if(s[0]=='*')return;
    if(s.size()==1){
        cout<<s[0];
        return;
    }
    vector<int>depth=get_depth(s);
    char root=s[0];
    int i=n-1;
    for(;i>=0;i--){
        if(depth[i]==1)break;
    }

    if(s[2]!='*'){
        string left=s.substr(2,i-3);
        in_order(left);
    }
    cout<<root;

    if(s[i]!='*'){
        string right=s.substr(i,n-i-1);
        in_order(right);
    }
}

int main(){
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        pre_order(s);
        in_order(s);
        cout<<endl;
    }
    return 0;
}