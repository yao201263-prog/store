#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//实际上，计算子树节点数时可以用数学方法直接计算
int main(){
    int m,n;
    while(cin>>m>>n&&m!=0){
        queue<int>q;
        q.push(m);
        int size=1;
        while(!q.empty()){
            int f=q.front();
            if(2*f<=n){
                q.push(2*f);
                size++;
        }
        if(2*f+1<n){
            q.push(2*f+1);
            size++;
        }
        q.pop();
        }
        cout<<size<<endl;
    }

    return 0;
}