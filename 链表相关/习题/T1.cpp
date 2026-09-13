#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int c;
    int n,x,y;
    cin>>c;
    while(c--){
        cin>>n>>x>>y;
        vector<int>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        reverse(arr.begin(),arr.end());
        int idx;
        for(int i=0;i<n;i++){
            if(arr[i]>x&&arr[i]<y){
                idx=i;
                break;
            }
        }

        cout<<arr[idx-1]<<" "<<arr[idx+1]<<endl;
    }
    return 0;
}