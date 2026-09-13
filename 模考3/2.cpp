#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vi>arr(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[j][i]>arr[k][i]){
                    swap(arr[j][i],arr[k][i]);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<((j==0)?"":" ")<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}

//6分钟