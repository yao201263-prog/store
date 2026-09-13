#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// 计算多项式值
double f(double a1, double a2, double a3, double a4, double a5, double b, double x) {
    return a1 * pow(x, 5) + a2 * pow(x, 4) + a3 * pow(x, 3) + a4 * pow(x, 2) + a5 * x + b;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略第一行后的换行符
    while (n--) {
        string line;
        getline(cin, line);
        // 将逗号替换为空格，便于 stringstream 解析
        for (char &c : line) if (c == ',') c = ' ';
        stringstream ss(line);
        double a1, a2, a3, a4, a5, b, left, right;
        ss >> a1 >> a2 >> a3 >> a4 >> a5 >> b >> left >> right;

        double l = left, r = right;
        double fl = f(a1, a2, a3, a4, a5, b, l);
        // 若端点恰为零点，直接输出
        if (fabs(fl) < 1e-12) {
            cout << fixed << setprecision(6) << l << endl;
            continue;
        }
        // 二分 60 次，保证精度远高于 1e-6
        for (int i = 0; i < 60; ++i) {
            double mid = (l + r) / 2;
            double fm = f(a1, a2, a3, a4, a5, b, mid);
            if (fl * fm > 0) { // 同号，零点在右侧
                l = mid;
                fl = fm;
            } else {
                r = mid;
            }
        }
        double ans = (l + r) / 2;
        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}