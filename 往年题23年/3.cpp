#include<bits/stdc++.h>
using namespace std;
vector<int>get_pre_order(vector<int>&in,vector<int>&post){
    int n=in.size();
    if(n==1||n==0)return in;
    int root=post[n-1];
    vector<int>lin,rin,lpost,rpost;
    //得到左右子树中序序列
    int i=0;
    for(;in[i]!=root;i++)lin.push_back(in[i]);
    i++;
    for(;i<n;i++)rin.push_back(in[i]);
    //得到后序序列
    for(int j=0;j<lin.size();j++)lpost.push_back(post[j]);
    for(int j=lin.size();j<n-1;j++)rpost.push_back(post[j]);
    //得到左右子树前序序列;
    vector<int>lpre,rpre;
    lpre=get_pre_order(lin,lpost);
    rpre=get_pre_order(rin,rpost);
    //得到最终结果
    vector<int>pre;
    pre.push_back(root);
    for(int j=0;j<lin.size();j++)pre.push_back(lpre[j]);
    for(int j=0;j<rpre.size();j++)pre.push_back(rpre[j]);
    return pre;
}
int main(){
    string line1,line2;
    getline(cin,line1);getline(cin,line2);
    istringstream iss1(line1);
    istringstream iss2(line2);
    vector<int>in_order,post_order;
    int token;
    while(iss1>>token)in_order.push_back(token);
    while(iss2>>token)post_order.push_back(token);
    vector<int>pre_order=get_pre_order(in_order,post_order);
    for(int i=0;i<pre_order.size();i++){
        cout<<((i==0)?"":" ")<<pre_order[i];
    }
    cout<<endl;
    return 0;
}