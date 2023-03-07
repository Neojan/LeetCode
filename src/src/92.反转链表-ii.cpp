/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
#if 0
    // 递归方法
    ListNode *succ = nullptr;
    ListNode *reverseN(ListNode *head, int n)
    {
        if (1 == n)
        {
            succ = head->next;
            return head;
        }
        ListNode *last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next       = succ;
        return last;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (1 == left)
        {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
#endif
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1);
        dummy->next     = head;
        int i           = 0;
        ListNode *pre         = dummy;// 记录反转前一个节点
        for (; i < left - 1; i++)
        {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next;
        for (i = 0; i < right - left; i++)
        {
            //先将 curr 的下一个节点记录为 next；
            //执行操作 ①：把 curr 的下一个节点指向 next 的下一个节点；
            //执行操作 ②：把 next 的下一个节点指向 pre 的下一个节点；
            //执行操作 ③：把 pre 的下一个节点指向 next。
            next = cur->next;
            cur->next = next->next;
            next->next       = pre->next;
            pre->next        = next;
        }
        return dummy->next;
    }
};
// @lc code=end

