#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    stack<int>s;
    string line;
    while(getline(cin,line)){
        if(line[0]=='p'&&line[1]=='u'){
            int pos=line.find(' ');
            string num=line.substr(pos);
            int x=stoi(num);
            s.push(x);
        }else if(line[0]=='p'&&line[1]=='o'){
            int x=s.top();
            cout<<x<<endl;
            s.pop();
        }else if(line[0]=='t'){
            cout<<s.top()<<endl;
        }else{
            cout<<((s.empty())?"true":"false")<<endl;
        }
    }

    return 0;
}