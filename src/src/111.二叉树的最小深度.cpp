/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode *> myQueue;
        //set<TreeNode*>         visited;
        myQueue.push(root);
        //visited.insert(root);

        TreeNode *temp = NULL;
        int       res  = 1;
        while(!myQueue.empty())
        {
            int sz = myQueue.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *temp = myQueue.front();
                myQueue.pop();
                //判断是否到终点
                if (temp->left == NULL && temp->right == NULL)
                {
                    return res;
                }
                // if(visited.find(temp) != visited.end())
                if (NULL != temp->left)
                    myQueue.push(temp->left);
                if (NULL != temp->right)
                    myQueue.push(temp->right);
            }
            res++;
        }

        return res;
    }
};
// @lc code=end

