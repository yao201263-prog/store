#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> prices(n);
        for (int i = 0; i < n; ++i) scanf("%d", &prices[i]);
        
        const int INF = 1e9;
        int buy1 = -INF, sell1 = 0, buy2 = -INF, sell2 = 0;
        for (int p : prices) {
            buy1 = max(buy1, -p);
            sell1 = max(sell1, buy1 + p);
            buy2 = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);
        }
        printf("%d\n", sell2);
    }
    return 0;
}