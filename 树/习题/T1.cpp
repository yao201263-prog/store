#include <iostream>
#include<cmath>
using namespace std;
bool f(int p,int q){
    //判断p，q是否同层
    if((int)(log2(p))!=(int)(log2(q))){
        return 0;
    }
    return 1;
}

int main(){
    int a,b;
    cin>>a>>b;
    int p=(a>b)?a:b;
    int q=(a>b)?b:a;
    while(p>q&&!f(p,q)){
        p/=2;
    }//p，q达到同一层

    if(p==q){
        cout<<p<<endl;
    }else{
        while(p!=q){
            p/=2;
            q/=2;
        }
        cout<<p<<endl;
    }

    return 0;
}

