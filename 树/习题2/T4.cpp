#include <iostream>
#include <vector>
#include <queue>
#include<stack>
using namespace std;
vector<int>parent,rnk;
int find(int x){
    if(parent[x]!=x){
        //根的父指针为自身
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    // 按秩合并：把秩小的树挂到秩大的树下
    if (rnk[x] < rnk[y])
        parent[x] = y;
    else {
        parent[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

int main(){
    int n,m;
    while(cin>>n>>m&&(n!=0||m!=0)){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;//父指针初始化为自身
        }
        rnk.assign(n,0);//初始化秩为0
        vector<vector<int>>stu_list;
        int k; 
        for(int i=0;i<m;i++){
            cin>>k;
            vector<int>seq(k);
            for(int j=0;j<k;j++){
                cin>>seq[j];//学生编号本身就是0—based
            }
            stu_list.push_back(seq);
        }
        
        
        for(int i=0;i<m;i++){
            int l=stu_list[i].size();
            for(int j=0;j<l-1;j++){
                unite(stu_list[i][j],stu_list[i][j+1]);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(find(i)==find(0))ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}