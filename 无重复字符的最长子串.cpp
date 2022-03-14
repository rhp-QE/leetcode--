#include <bits/stdc++.h>
#include <iostream>
using namespace ::std;
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> appear;
        int left = 0, right = 0;
        int n = s.size();
        int ans = 0;
        while (right < n) {
            while (right < n && appear.find(s[right]) == appear.end())
                appear.insert(s[right]), ++right;
            ans = max(ans, right - left);
            if (right == n)
                break;
            appear.erase(s[left++]);
        }
        return ans;
    }
};
