#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

// 从一行字符串中读取多项式，存入map<幂次,系数>，幂次为负则停止
map<int,int> readPoly(const string& line){
    map<int,int> poly;
    istringstream iss(line);
    int coef, exp;
    while(iss >> coef >> exp){
        if(exp < 0) break;  // 幂次为负，本行结束
        poly[exp] += coef;
    }
    return poly;
}

map<int,int> add_p(const map<int,int>& v1, const map<int,int>& v2){
    map<int,int> ans = v1;
    for(auto& kv : v2){
        ans[kv.first] += kv.second;
    }
    return ans;
}

int main(){
    int n; cin >> n;
    cin.ignore(); // 跳过n后面的换行
    while(n--){
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);

        map<int,int> v1 = readPoly(line1);
        map<int,int> v2 = readPoly(line2);
        map<int,int> ans = add_p(v1, v2);

        // 按幂次从高到低输出，系数为0跳过
        bool first = true;
        for(auto it = ans.rbegin(); it != ans.rend(); it++){
            if(it->second == 0) continue;
            if(!first) cout << " ";
            cout << "[ " << it->second << " " << it->first << " ]";
            first = false;
        }
        cout << endl;
    }
    return 0;
}