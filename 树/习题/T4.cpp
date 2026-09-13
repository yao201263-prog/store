#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
string f(string t1,string t2){
    if(t1.empty())return"";
    char root=t1[0];
    int pos=t2.find(root);
    string lt2=t2.substr(0,pos);
    string rt2=t2.substr(pos+1);
    string lt1=t1.substr(1,lt2.size());
    string rt1=t1.substr(lt2.size()+1);
    return f(lt1,lt2)+f(rt1,rt2)+root;
}

int main(){
    string t1,t2;
    while(cin>>t1>>t2){
        cout<<f(t1,t2)<<endl;
    }
    return 0;
}