#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>&a,vector<int>&b){
    for(int i=0;i<a.size();i++){
        if(a[i]<b[i])return 0;
    }
    return 1;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int num=0;
        while(!check(a,b)){
            a.erase(a.begin());
            a.push_back(100);
            num++;
        }
        cout<<num<<endl;
    }
    return 0;
}