#include <bits/stdc++.h>
#include <ios>
#include <iostream>
using namespace ::std;

/* 经典双指针操作 */
/* 注意：要求出不重复的数字组合 应该在枚举时每一位都不同 */
/*     ,这样并不会出错，因为两个相同的数字，前一个数字一定会包括后面数字的所有情况 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int left = 0; left + 2 < n; ++left) {
            if (left > 0 && nums[left] == nums[left - 1])
                continue;
            int mid = left + 1;
            int right = n - 1;
            while (right > mid) {
                int cur_sum = nums[left] + nums[mid] + nums[right];
                if (cur_sum == 0) {
                    ans.push_back({ nums[left], nums[mid], nums[right] });
                    ++mid;
                    while (mid < n && nums[mid] == nums[mid - 1])
                        ++mid;
                } else if (cur_sum < 0) {
                    ++mid;
                    while (mid < n && nums[mid] == nums[mid - 1])
                        ++mid;
                } else if (cur_sum > 0) {
                    --right;
                    while (right >= 0 && nums[right] == nums[right + 1])
                        --right;
                }
            }
        }
        return ans;
    }
};
