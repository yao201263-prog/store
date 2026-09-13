#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long cat[20] = {0};  
    cat[0] = 1;           
    for (int i = 1; i <= 19; ++i) {
        for (int j = 0; j < i; ++j) {
            cat[i] += cat[j] * cat[i - 1 - j];
        }
    }
    cout << cat[n] << " " << cat[k - 1] * cat[n - k] << endl;
    return 0;
}