/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> vistor;
        ListNode                 *p1 = headA;
        ListNode                 *p2 = headB;
        while (p1)
        {
            vistor.insert(p1);
            p1 = p1->next;
        }
        while(p2)
        {
            if(vistor.count(p2))
            {
                return p2;
            }
            p2 = p2->next;
        }
        return p2;
    }
};
// @lc code=end

