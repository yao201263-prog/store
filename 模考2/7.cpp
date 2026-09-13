#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<string> seq(N);
        for (int i = 0; i < N; ++i) {
            cin >> seq[i];
        }

        // 空树：只有一个 '#'
        if (N == 1 && seq[0] == "#") {
            cout << "T" << endl;
            continue;
        }
        // 其他 N==1 的情况（例如一个数字）都不合法
        if (N == 1) {
            cout << "F" << endl;
            continue;
        }

        stack<int> st;   // 栈顶存储当前节点还需要多少个子节点（初始2）
        bool valid = true;

        for (const string& s : seq) {
            if (s == "#") {
                if (st.empty()) {
                    valid = false;
                    break;
                }
                // 当前节点消耗一个空孩子
                st.top()--;
                // 如果该节点已满（两个孩子都处理完），则弹出
                while (!st.empty() && st.top() == 0) {
                    st.pop();
                }
            } else {
                // 遇到数字，压入一个新节点，它需要2个子节点
                st.push(2);
            }
        }

        // 最终栈必须为空，否则有节点未处理完
        if (!st.empty()) valid = false;

        cout << (valid ? "T" : "F") << endl;
    }
    return 0;
}