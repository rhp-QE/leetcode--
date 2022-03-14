#include <bits/pthreadtypes-arch.h>
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace ::std;

class Solution {
public:
    typedef long long ll;
    int myAtoi(string s)
    {
        int pos = 0;
        int n = s.size();
        while (pos < n && s[pos] == ' ')
            ++pos;

        if (pos == n)
            return 0;
        int op = 1;
        ll ans = 0;
        if (s[pos] == '-')
            op = -1, ++pos;
        else if (s[pos] == '+')
            ++pos;
        while (pos < n && (s[pos] >= '0' && s[pos] <= '9')) {
            ans *= 10;
            ans += s[pos] - '0';
            if (ans >= (1LL << 31)) {
                if (1 == op)
                    return INT_MAX;
                else if (-1 == op)
                    return INT_MIN;
            }
            ++pos;
        }
        return op * ans;
    }
};
