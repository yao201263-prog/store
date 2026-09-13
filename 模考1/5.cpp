#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(){
    int N;cin>>N;
    vector<int>left(N+1);
    vector<int>right(N+1);
    for(int i=1;i<N+1;i++){
        cin>>left[i]>>right[i];
    }

    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            int f=q.front();
            if(left[f]!=-1)q.push(left[f]);
            if(right[f]!=-1)q.push(right[f]);
            if(i==0){
                cout<<((f==1)?"":" ")<<f;
            }
            q.pop();
        }
    }
    return 0;
}