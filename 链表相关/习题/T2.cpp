#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int c;cin>>c;
    int n,x;
    while(c--){
        cin>>n>>x;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int flag=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=x){
                if(!flag){
                    cout<<arr[i];
                    flag=1;
                }else{
                    cout<<" "<<arr[i];
                }
            }
        }
        cout<<endl;
    }
    return 0;
}