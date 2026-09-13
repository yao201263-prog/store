#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef struct spot{
    string name;
    float x,y;
}spot;

typedef struct PDnum{
    float px,py,num;
}pd;


void find_pd(pd pd0,vector<spot> &mp){
    int n=mp.size();
    vector<int>flag(n,0);
    for(int i=0;i<n;i++){
        float L=sqrt((mp[i].x-pd0.px)*(mp[i].x-pd0.px)
    +(mp[i].y-pd0.py)*(mp[i].y-pd0.py));
        if(L<=pd0.num){
            flag[i]=1;
        }
    }
    
    int f=0;
    for(int i=0;i<n;i++){
        if(flag[i]){
           if(f==0){
            cout<<mp[i].name;
            f=1;
           }else{
            cout<<" "<<mp[i].name;
           } 
        }
    }

    cout<<endl;
}


int main(){
    int spotnum;
    cin>>spotnum;
    vector<spot>mp;
    spot sp0;
    while(spotnum--){
        cin>>sp0.name>>sp0.x>>sp0.y;
        mp.push_back(sp0);
    }

    int PDnum;cin>>PDnum;
    vector<pd>pds(PDnum);
    for(int i=0;i<PDnum;i++){
        cin>>pds[i].px>>pds[i].py>>pds[i].num;
    }

    for(int i=0;i<PDnum;i++){
        find_pd(pds[i],mp);
    }

    return 0;
}