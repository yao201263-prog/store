#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct student{
    int num;
    string name;
    int score;
}stu;

void swap(stu& a,stu& b){
    stu temp;
    temp=b;
    b=a;
    a=temp;
}

int main(){
    stu stu0;
    vector<stu>list;
    while(cin>>stu0.num>>stu0.name>>stu0.score){
        list.push_back(stu0);
    }

    for(int i=0;i<list.size();i++){
        for(int j=i+1;j<list.size();j++){
            if(list[i].score<list[j].score){
                swap(list[i],list[j]);
            }
        }
    }
    
    for(int i=0;i<list.size();i++){
        cout<<list[i].num<<" "<<list[i].name
        <<" "<<list[i].score<<endl;
    }

    return 0;
}