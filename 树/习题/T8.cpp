#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct Node{
    int index;//自身下标
    int l;
    int r;//左右子节点下标
};

int main(){
    int N;cin>>N;
    Node list[N]; //list[i]代表颜色编号为i的节点
    for(int i=0;i<N;i++){
        cin>>list[i].l>>list[i].r;
        list[i].index=i;
    }
    queue<Node>q;
    q.push(list[0]);
    int idx=1;//标记层序
    while(!q.empty()){
        int qsize=q.size();
        for(int i=0;i<qsize-1;i++){
            Node f=q.front();
            if(f.l!=-1) q.push(list[f.l-1]);
            if(f.r!=-1) q.push(list[f.r-1]);
            q.pop();
        }
        Node f0=q.front();
        if(f0.l!=-1) q.push(list[f0.l-1]);
        if(f0.r!=-1) q.push(list[f0.r-1]);
        cout<<((idx==1)?"":" ")<<(f0.index+1);
        q.pop();
        idx++;
    }
    cout<<endl;
    return 0;
}