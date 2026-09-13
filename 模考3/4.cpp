#include<bits/stdc++.h>
using namespace std;
bool ifstop(queue<int>q,int t){
    while(!q.empty()){
        int f=q.front();
        if(f==t)return 0;
        q.pop();
    }
    return 1;
}

int main(){
    int n;cin>>n;
    while(n--){
        int m;cin>>m;
        vector<int>children;
        vector<int>candies;
        queue<int>child;
        stack<int>candy;
        for(int i=0;i<m;i++){
            int c;cin>>c;
            children.push_back(c);
        }

        for(int i=0;i<m;i++){
            int x;cin>>x;
            candies.push_back(x);
        }

        for(int i=m-1;i>=0;i--){
            child.push(children[i]);
            candy.push(candies[i]);
        }
        
        while(!child.empty()&&!ifstop(child,candy.top())){
            int t=candy.top();
            while(child.front()!=t){
                int f=child.front();
                child.pop();child.push(f);//队首小孩去队尾
            }

            child.pop();candy.pop();//队首的小孩拿走喜欢的糖
        }
        cout<<candy.size()<<endl;
    }
    return 0;
}
//半小时