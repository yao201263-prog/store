#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct spot{
    string name;
    float x,y;
}spot;

void findname(string name0,vector<spot>&mp){
    int n=mp.size();
    int idx;
    for(int i=0;i<n;i++){
        if(mp[i].name==name0){
            idx=i;
        }
    }
    cout<<mp[idx].x<<" "<<mp[idx].y<<endl;
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

    int searchNum;
    cin>>searchNum;
    vector<string>names(searchNum);
    for(int i=0;i<searchNum;i++){
        cin>>names[i];
    }

    for(int i=0;i<searchNum;i++){
        findname(names[i],mp);
    }
    return 0;
}