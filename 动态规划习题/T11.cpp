#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;cin>>N;
    while(N--){
        int k;cin>>k;
        vector<int>price(k);
        for(int i=0;i<k;i++){cin>>price[i];}
        int w=0;
        for(int i=1;i<k;i++){
            if(price[i]>price[i-1]){
                w+=(price[i]-price[i-1]);
            }else{
                continue;
            }
        }
        cout<<w<<endl;
    }
    return 0;
}