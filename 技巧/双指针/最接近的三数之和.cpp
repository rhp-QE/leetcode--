#include <bits/stdc++.h>
#include <iostream>
using namespace ::std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int ans = 1e9;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int left = 0; left + 2 < n; ++left) {
            int mid = left + 1;
            int right = n - 1;
            while (right > mid) {
                int sum = nums[left] + nums[mid] + nums[right];
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
                if (sum > target)
                    --right;
                else if (sum < target)
                    ++mid;
                else
                    return target;
            }
        }
        return ans;
    }
};
