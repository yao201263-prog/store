#include<iostream>
#include<string>
using namespace std;
int main(){
    double w0=100.00;
    double w=w0,w_if=w0;
    string s;cin>>s;
    int n=s.size();

    for(int i=0;i<n;i++){
        if(i%7!=6){
            w_if*=1.01;
            if(s[i]=='s')w*=1.01;
            if(s[i]=='r')w*=0.99;
        }else{
            if(s[i]=='s')w*=1.01;w_if*=1.01;
        }
    }

    int cnt = 0;
    string pattern = "sssrr";
    for (int i = 0; i <= n - 5; ++i) {
        if (s.substr(i, 5) == pattern) {
            cnt++;
        }
    }
    cout<<(int)w<<endl;
    cout<<(int)w_if<<endl;
    cout<<cnt<<endl;
    return 0;
}