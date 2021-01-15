/// @file    Sum.cc
/// @author  moyin(moyin1004@163.com)
/// @data    2021-01-15 20:32:11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> hash;
            vector<int> ans;
            int size = nums.size();
            for (int i = 0; i < size; ++i) {
                auto it = hash.find(nums[i]);
                if (it != hash.end()) {
                    ans.push_back(it->second);
                    ans.push_back(i);
                    return ans;
                }
                hash[target-nums[i]] = i;
            }
            return ans;
        }
};

int main() {
    Solution s;
    vector<int> nums;
    vector<int> ans;
    int n, target;
    cin >> n >> target;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    ans = s.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
