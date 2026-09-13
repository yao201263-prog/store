#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<iomanip>
using namespace std;
int main(){
    int N;cin>>N;
    vector<int>people(N);
    for(int i=0;i<N;i++){cin>>people[i];}
    sort(people.begin(),people.end());
    int limit;cin>>limit;
    int num=0,l=0,r=N-1;
    while(l<=r){
        if(people[l]+people[r]<=limit){
            l++;r--;
        }else{
            r--;
        }
        num++;
    }
    cout<<num<<endl;
    return 0;
}