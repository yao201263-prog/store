#include <iostream>
#include <vector>
#include <queue>
#include<stack>
using namespace std;
typedef struct Node{
    char data;
    int lc,rc;
    Node(){
        data=' ';
        lc=-1;rc=-1;
    }
};


int main(){
    int n;cin>>n;
    vector<char>datas(n);//储存对应节点数据
    vector<vector<int>>tree;//储存子表
    vector<int>hasp(n,0);
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        datas[i]=c;
        int x;
        vector<int>children;
        while(cin>>x&&x!=0){
            children.push_back(x-1);
            hasp[x-1]=1;
        }
        tree.push_back(children);
    }

    int root=1;
    for(int i=0;i<n;i++){
        if(!hasp[i]){
            root=i;
            break;
        }
    }


    vector<Node>biTr(n);
    for(int i=0;i<n;i++){//处理左孩子
        biTr[i].data=datas[i];
        if(tree[i].size()!=0){//有孩子
            biTr[i].lc=tree[i][0];
        }
    }

    for(int i=0;i<n;i++){//处理右孩子
        if(tree[i].size()!=0){
            int m=tree[i].size();
            for(int j=0;j<m-1;j++){
                biTr[tree[i][j]].rc=tree[i][j+1];
            }
        }
    }

    //前序
    stack<int>st1;
    st1.push(root);
    while(!st1.empty()){
        int u=st1.top();st1.pop();
        cout<<biTr[u].data;
        if (biTr[u].rc != -1) st1.push(biTr[u].rc);
        if (biTr[u].lc != -1) st1.push(biTr[u].lc);
    }
    cout<<endl;

    // 后根遍历（二叉树的中序遍历）
    stack<int> st2;
    int u = root;
    while (u != -1 || !st2.empty()) {
        while (u != -1) {
            st2.push(u);
            u = biTr[u].lc;
        }
        u = st2.top(); st2.pop();
        cout << biTr[u].data;
        u = biTr[u].rc;
    }
    cout << endl;

    return 0;
}