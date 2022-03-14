#include <bits/stdc++.h>
#include <iostream>
using namespace ::std;

/* 双指针 分别指向头尾  向中间夹逼出最优解 */

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (right > left) {
            ans = max(ans, (right - left) * min(height[left], height[right]));
            if (height[left] <= height[right])
                ++left;
            else
                --right;
        }
        return ans;
    }
};
