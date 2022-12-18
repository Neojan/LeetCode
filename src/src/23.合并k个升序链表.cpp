/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    struct Status
    {
        int       val;
        ListNode *ptr;
        bool      operator<(const Status &rhs) const
        {
            return val > rhs.val;
        }
    };
    priority_queue<Status> pq;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *newList = new ListNode(-1);
        ListNode                                          *p       = newList;
        // for (vector<ListNode *>::iterator iter = lists.begin(); iter != lists.end();iter++)
        // {
        //     pq.push({(*iter)->val, *iter});
        // }
        for (auto head:lists)
        {
            if(head)
            {
                pq.push({head->val, head});
            }
        }
        while (!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            p->next = f.ptr;
            p       = p->next;
            if (f.ptr->next)
                pq.push({f.ptr->next->val, f.ptr->next});
        }
        return newList->next;
    }
};
// @lc code=end

