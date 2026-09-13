#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll merge(vector<ll>&arr,vector<ll>&arr1,ll low,ll m,ll high){
    ll i,j,k;
    ll num=0;
    i=low;j=m+1;k=low;
    while(i<=m&&j<=high){
        if(arr[i]<arr[j]){arr1[k++]=arr[i++];}
        else{ arr1[k++]=arr[j++];num+=(m-i+1);}
    }

    while(i<=m)arr1[k++]=arr[i++];
    while(j<=high)arr1[k++]=arr[j++];
    return num;
}

ll mergePass(vector<ll>&arr,vector<ll>&arr1,ll n,ll l){
    //l代表有序子文件长度
    ll i=0,j;ll num=0;
    while(i+2*l<n+1){
        num+=merge(arr,arr1,i,i+l-1,i+2*l-1);
        i+=2*l;
    }

    if(i+l<n)num+=merge(arr,arr1,i,i+l-1,n-1);
    else for(j=i;j<n;j++)arr1[j]=arr[j];
    return num;
}

ll get_ans(vector<ll>&arr){
    ll n=arr.size();
    vector<ll>arr1(n);
    ll l=1;ll num=0;
    while(l<n){
        num+=mergePass(arr,arr1,n,l);
        l*=2;
        num+=mergePass(arr1,arr,n,l);
        l*=2;
    }
    return num;
}

int main(){
    ll n;cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    ll num=get_ans(arr);
    cout<<num<<endl;
    return 0;
}