#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> p;
    int x;
    while(cin >> x){
        p.push_back(x);
    }

    // 求导：每对(coef, exp) -> (coef*exp, exp-1)，exp==0的项跳过
    vector<pair<int,int>> ans;
    for(int i = 0; i < (int)p.size()-1; i += 2){
        int coef = p[i];
        int exp  = p[i+1];
        if(exp == 0) continue;
        int ncoef = coef * exp;
        if(ncoef == 0) continue;
        ans.push_back({ncoef, exp-1});
    }

    // 输出
    if(ans.empty()){
        cout << "0 0" << endl;
    } else {
        for(int i = 0; i < (int)ans.size(); i++){
            if(i != 0) cout << " ";
            cout << ans[i].first << " " << ans[i].second;
        }
        cout << endl;
    }
    return 0;
}