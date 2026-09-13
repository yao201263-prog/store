#include<bits/stdc++.h>
using namespace std;
string trim_zero(const string &s) {
    size_t pos = s.find_first_not_of('0');
    return (pos == string::npos) ? "0" : s.substr(pos);
}
bool cmp(int a,int b){
    string x=trim_zero(to_string(a));reverse(x.begin(),x.end());
    string y=trim_zero(to_string(b));reverse(y.begin(),y.end());
    if(x!=y)return stoi(x)>stoi(y);
    return a<b;
}
int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }

    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<((i==0)?"":" ")<<arr[i];
    }
    cout<<endl;
    return 0;
}