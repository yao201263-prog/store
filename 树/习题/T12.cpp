#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 定义堆中的元素：和，当前cur的索引，当前b的索引
struct Node {
    int sum;
    int i; // cur中的索引
    int j; // 当前序列中的索引
    // 最小堆需要重载大于号
    bool operator>(const Node& other) const {
        return sum > other.sum;
    }
};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int m, n;
        scanf("%d%d", &m, &n);
        vector<vector<int>> seq(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &seq[i][j]);
            }
            sort(seq[i].begin(), seq[i].end()); // 每个序列排序
        }

        // 初始 cur 为第一个序列
        vector<int> cur = seq[0];

        // 依次合并后续序列
        for (int k = 1; k < m; ++k) {
            // 最小堆
            priority_queue<Node, vector<Node>, greater<Node>> pq;
            // 将 cur[i] + seq[k][0] 全部入堆
            for (int i = 0; i < n; ++i) {
                pq.push({cur[i] + seq[k][0], i, 0});
            }

            vector<int> next_cur;
            while (next_cur.size() < n) {
                Node top = pq.top(); pq.pop();
                next_cur.push_back(top.sum);
                // 如果还可以继续往后取该 cur[i] 对应的下一个 seq[k] 的元素
                if (top.j + 1 < n) {
                    pq.push({cur[top.i] + seq[k][top.j + 1], top.i, top.j + 1});
                }
            }
            cur = move(next_cur); // 更新 cur
        }

        // 输出结果
        for (int i = 0; i < n; ++i) {
            if (i > 0) printf(" ");
            printf("%d", cur[i]);
        }
        printf("\n");
    }
    return 0;
}