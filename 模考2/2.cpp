#include<bits/stdc++.h>
using namespace std;
int cards[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;cin>>N>>K;
    for(int i=0;i<N;i++)cin>>cards[i];
    int i=0,j=0;
    long long multi=1;
    long long ans=0;
    
    if(N==1&&cards[0]>=K){
        cout<<1<<endl;
        return 0;
    }else if(N==1&&cards[0]<K){
        cout<<0<<endl;
        return 0;
    }

    while(j<N){
        
        while(multi<K&&j<N){
            multi*=cards[j];j++;
        }
        while(multi>=K){
            ans+=N-j+1;
            multi/=cards[i];
            i++;
        }
    }

    cout<<(ans%233333)<<endl;
    return 0;
    
}