#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace ::std;

/* Manacher's Algorithm */

/* pos : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 */
/* char: $ # a # b # a # b # a  #  a  #  b  #  c  # */
/* id  :     0   1   2   3   4     5     6     7 */
/* 半径：    2   4   6   4   2     2     2     2 */
/* =>   长度=半径-1  起始位置=(pos-半径+1)/2 */

class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        vector<char> new_str(2 * n + 2);
        new_str[0] = '$';
        int len = 1;
        for (char x : s) {
            new_str[len++] = '#';
            new_str[len++] = x;
        }
        new_str[len++] = '#';
        int mid = 0, right = 1;

        //带中点的半径
        vector<int> ans(len);
        for (int i = 1; i < len; ++i) {
            if (i < right)
                ans[i] = min(right - i, ans[2 * mid - i]);
            else
                ans[i] = 1;
            while (i + ans[i] < len && new_str[i + ans[i]] == new_str[i - ans[i]])
                ++ans[i];
            if (i + ans[i] > right) {
                right = i + ans[i];
                mid = i;
            }
        }
        pair<int, int> res;
        res.first = 0;
        for (int i = 1; i < len; ++i) {
            if (ans[i] - 1 > res.first) {
                res.first = ans[i] - 1;
                res.second = (i - ans[i] + 1) / 2;
            }
        }
        return s.substr(res.second, res.first);
    }
};
