/// @file    4.MedianOfTwoSortedArrays.cc
/// @author  moyin(moyin1004@163.com)
/// @data    2021-01-30 20:59:23

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 解法方法来自bilibili
// https://www.bilibili.com/video/BV17A411H77u?from=search&seid=18194451406086170037

class Solution {
public:
    // 寻找第pos（从1开始）位置的数
    int binary_search(vector<int> &nums1, vector<int> &nums2,
            int start1, int start2, int pos) {
        if (start1 >= (int)nums1.size()) return nums2[start2 + pos - 1];
        if (start2 >= (int)nums2.size()) return nums1[start1 + pos - 1];
        if (pos == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        int mid = min(pos/2, min((int)nums1.size()-start1, (int)nums2.size()-start2));
        // 每次剪除前mid个数
        if (nums1[start1 + mid -1] < nums2[start2 + mid -1]) {
            return binary_search(nums1, nums2, start1 + mid, start2, pos - mid);
        } else {
            return binary_search(nums1, nums2, start1, start2 + mid, pos - mid);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_length = nums1.size() + nums2.size();
        if (total_length % 2 == 1) {
            return binary_search(nums1, nums2, 0, 0, total_length/2+1);
        } else {
            return ((double)binary_search(nums1, nums2, 0, 0, total_length/2) +
                    (double)binary_search(nums1, nums2, 0, 0, total_length/2+1)) / 2;
        }
    }
};

void read(vector<int> &v) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
}

int main() {
    vector<int> v1;
    vector<int> v2;
    Solution s;
    int n = 0;
    cin >> n;
    while (n--) {
        v1.clear();
        v2.clear();
        read(v1);
        read(v2);
        double ans;
        cin >> ans;
        double ex = s.findMedianSortedArrays(v1, v2);
        cout << "ans = " << ex << endl;
        cout << (fabs(ex - ans) <= 1e-8) << endl << endl;
    }
    return 0;
}
