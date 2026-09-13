#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>rwd1(n),rwd2(n);
    for(int i=0;i<n;i++)cin>>rwd1[i];
    for(int i=0;i<n;i++)cin>>rwd2[i];
    int k;cin>>k;
    vector<int>sub(n);
    for(int i=0;i<n;i++){
        sub[i]=rwd1[i]-rwd2[i];
    }
    sort(sub.begin(),sub.end());
    int bestsum=0;
    for(int i=0;i<n;i++)bestsum+=rwd2[i];
    for(int i=0;i<k;i++){
        bestsum+=sub[n-i-1];
    }
    cout<<bestsum<<endl;
    return 0;
}