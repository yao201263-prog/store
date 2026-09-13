#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<iomanip>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for (int i = 0; i < m; ++i) cin >> nums1[i];
    for (int i = 0; i < n; ++i) cin >> nums2[i];

    // 确保 nums1 是较短的数组
    if (m > n) {
        swap(nums1, nums2);
        swap(m, n);
    }

    int left = 0, right = m;
    int halfLen = (m + n + 1) / 2;

    while (left <= right) {
        int i = (left + right) / 2;   // nums1 左边有 i 个元素
        int j = halfLen - i;          // nums2 左边有 j 个元素

        int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == m) ? INT_MAX : nums1[i];
        int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == n) ? INT_MAX : nums2[j];

        if (left1 <= right2 && left2 <= right1) {
            // 找到正确分割
            if ((m + n) % 2 == 1) {
                // 奇数，中位数是左边最大值
                cout << fixed << setprecision(1) << (double)max(left1, left2) << endl;
            } else {
                // 偶数，中位数是 (左边最大 + 右边最小) / 2.0
                int leftMax = max(left1, left2);
                int rightMin = min(right1, right2);
                cout << fixed << setprecision(1) << (leftMax + rightMin) / 2.0 << endl;
            }
            return 0;
        } else if (left1 > right2) {
            // 左1太大，需要减小 i
            right = i - 1;
        } else {
            // left2 > right1，需要增大 i
            left = i + 1;
        }
    }

    return 0;
}