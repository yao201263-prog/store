#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;cin>>m;
    while(m--){
        int n;cin>>n;
        vector<int>arr(n);
        vector<int>time(5001,0);
        for(int i=0;i<n;i++){cin>>arr[i];time[arr[i]]++;}
        bool flg=0;int idx=-1;
        vector<int>visited(5001,0);
        for(int i=0;i<n;i++){
            if(time[arr[i]]>=2&&!flg){
                flg=1; visited[arr[i]]=1;
            }else if(time[arr[i]]>=2&&flg&&!visited[arr[i]]){
                idx=i;
                break;
            }
           
        }

        if(idx==-1){
            cout<<"NOT EXIST"<<endl;
        }else{
            cout<<arr[idx]<<endl;
        }
    }
    return 0;
}