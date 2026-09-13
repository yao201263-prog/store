#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main(){
    string s;
    set<string>sp;
    while(cin>>s){
       sp.insert(s);
    }

    cout<<sp.size()<<endl;
    int i=0;
    for(auto it:sp){
        cout<<((i%4==0)?"":" ")<<it;
        if(i%4==3){
            cout<<endl;
        }
        i++;
    }

    return 0;
}