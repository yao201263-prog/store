#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tails;  
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        auto it = upper_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << tails.size() << endl;
    return 0;
}