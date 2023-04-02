/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    char leftOf(char c)
    {
        if (c == '}')
            return '{';
        else if (c == ']')
            return '[';
        else
            return '(';
    }
    bool isValid(string s) {
        stack<char> m;
        for(char c:s)
        {
            if (c == '(' || c == '[' || c=='{')
            {
                m.push(c);
            }
            else
            {
                if (m.empty())
                {
                    return false;
                }
                char d = m.top();
                m.pop();
                if (d != leftOf(c))
                {
                    return false;
                }
            }
        }
        return m.empty() ? true : false;
    }
};
// @lc code=end

