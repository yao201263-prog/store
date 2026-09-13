#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void cutZero(string&s){
    int i = 0;
    while (i < s.size() && s[i] == '0') i++;
    if (i == s.size()) s = "0";
    else s = s.substr(i);
}

int main(){
    string s;cin>>s;
    int m;cin>>m;
    string s0="";int del=m;
    s0.push_back(s[0]);
    for(int i=1;i<s.size();i++){
        while(del>0&&s[i]<s0.back()&& !s0.empty()){
            s0.pop_back();
            del--;
        }
        s0.push_back(s[i]);
    }

    if(del>0&& !s0.empty()){
        while(del--){
            s0.pop_back();
        }
    }

    cutZero(s0);
    cout<<s0<<endl;
    return 0;
}