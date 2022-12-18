/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // ListNode *findFromEnd(ListNode *head, int n)
    // {
    //     ListNode *p1 = head;
    //     for (int i = 0; i < n; i++)
    //     {
    //         p1 = p1->next;
    //     }
    //     ListNode *p2 = head;
    //     while (p1)
    //     {
    //         p1 = p1->next;
    //         p2 = p2->next;
    //     }
    //     return p2;
    // }
    // ListNode* removeNthFromEnd(ListNode* head, int n)
    // {
    //     ListNode *myDummy = new ListNode(-1);
    //     myDummy->next      = head;
    //     ListNode *p       = findFromEnd(myDummy, n + 1);
    //     if (p->next)
    //         p->next       = p->next->next;
    //     else
    //         myDummy->next = nullptr;
    //     return myDummy->next;
    // }
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *p1      = head;
        ListNode *myDummy = new ListNode(-1);
        myDummy->next     = head;
        int len           = 0;
        while (p1)
        {
            len++;
            p1 = p1->next;
        }
        ListNode *p2 = myDummy;
        for (int i = 0; i < len - n; i++)
        {
            p2 = p2->next;
        }
        if (p2->next)
            p2->next = p2->next->next;

        return myDummy->next;
    }
};
// @lc code=end

