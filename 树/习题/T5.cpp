#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef vector<int> vi;

vi getpre(vi& in, vi& aft) {
    if (in.empty()) return vi();
    int n = in.size();
    int root = aft[n - 1];               
    int pos = find(in.begin(), in.end(), root) - in.begin();
    vi lin(in.begin(), in.begin() + pos);    
    vi rin(in.begin() + pos + 1, in.end());   
    vi laft(aft.begin(), aft.begin() + pos);          
    vi raft(aft.begin() + pos, aft.end() - 1);         
    vi lpre = getpre(lin, laft);
    vi rpre = getpre(rin, raft);
    vi res;
    res.push_back(root);
    res.insert(res.end(), lpre.begin(), lpre.end());
    res.insert(res.end(), rpre.begin(), rpre.end());
    return res;
}

int main(){
    vi arr,in,aft;
    int x;
    while(cin>>x){
        arr.push_back(x);
    }
    int n=arr.size()/2;
    for(int i=0;i<n;i++){
        in.push_back(arr[i]);
        aft.push_back(arr[n+i]);
    }

    vi pre = getpre(in, aft);
    for (size_t i = 0; i < pre.size(); ++i) {
        if (i) cout << ' ';
        cout << pre[i];
    }
    cout << endl;
    return 0;
}