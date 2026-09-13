#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>times(1000,-1);
    for(int i=0;i<n;i++){
        times[arr[i]]++;
    }

    int num=0;
    for(int i=0;i<1000;i++){
        if(times[i]==-1){
            continue;
        }else{
            num+=(times[i]/(i+1)+1)*(i+1);
        }
    }    
    cout<<num<<endl;
}

//26min;