/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *pDummyLeft = new ListNode(-1);
        ListNode *p1          = pDummyLeft;
        ListNode *pDummyRight = new ListNode(-1);
        ListNode *p2          = pDummyRight;

        ListNode *p           = head;
        while (p)
        {
            if (p->val < x)
            {
                p1->next = p;
                p1       = p1->next;
            }
            else
            {
                p2->next = p;
                p2       = p2->next;
            }
            //一定不要忘了断开原先指针连接
            ListNode *temp = p->next;
            p->next        = nullptr;
            p              = temp;
        }
        p1->next = pDummyRight->next;
        return pDummyLeft->next;
    }
};
// @lc code=end

