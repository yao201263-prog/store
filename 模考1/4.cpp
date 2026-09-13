#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(){
    int N;cin>>N;cin.ignore();  
    queue<int>q1,q2;
    int i=0;
    string line;
    while(getline(cin,line)){
        if(line[1]=='u'){
            i++;
            int type=line[5]-'0';
            if(type==1){
                q1.push(i);
            }else{
                q2.push(i);
            }
        }else{
            int type=line[4]-'0';
            if(type==0){
                if(q1.empty()&&q2.empty()){
                    cout<<-1<<" "<<-1<<endl;
                }else if(q1.empty()){
                    cout<<q2.front()<<" "<<2<<endl;
                    q2.pop();
                }else if(q2.empty()){
                    cout<<q1.front()<<" "<<1<<endl;
                    q1.pop();
                }else{
                    if(q1.front()<q2.front()){
                        cout<<q1.front()<<" "<<1<<endl;
                        q1.pop();
                    }else{
                        cout<<q2.front()<<" "<<2<<endl;
                        q2.pop();
                    }
                }
            }else if(type==1){
                if(q1.empty()){
                    cout<<-1<<" "<<-1<<endl;
                }else{
                    cout<<q1.front()<<" "<<1<<endl;
                    q1.pop();
                }
            }else{
                if(q2.empty()){
                    cout<<-1<<" "<<-1<<endl;
                }else{
                    cout<<q2.front()<<" "<<2<<endl;
                    q2.pop();
                }
            }
        }
    }
    return 0;
}