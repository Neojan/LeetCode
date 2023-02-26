/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        #if 0
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *last = reverseList(head->next);
        head->next->next     = head;
        head->next           = NULL;
        return last;
        #endif
        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev      = cur;
            cur       = next;
        }
        return prev;
    }
};
// @lc code=end

