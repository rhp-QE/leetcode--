#include <bits/stdc++.h>
#include <iostream>
using namespace ::std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode ans_node(0, nullptr);
        ListNode* ptr = &ans_node;
        int pre = 0;
        while (0 != pre || l1 || l2) {
            int ans = pre;
            if (l1)
                ans += l1->val;
            if (l2)
                ans += l2->val;
            ptr->next = new ListNode(ans % 10, nullptr);
            pre = ans / 10;
            ptr = ptr->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        ptr->next = nullptr;
        return ans_node.next;
    }
};
