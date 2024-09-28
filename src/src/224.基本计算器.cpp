/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        int sum = 0;
        int temp = 0;
        int pre = 0;
        char sign = '+';
        stack<int> nums;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
                temp = (temp * 10 + (s[i] - '0'));

            if (!isdigit(s[i]) && s[i] != ' ' || i == s.length() - 1)
            {
                switch (sign)
                {
                case '+':
                    nums.push(temp); break;
                case '-':
                    nums.push(-temp); break;
                default:
                    break;
                }

                temp = 0;
                sign = s[i];
            }
        }
        while (!nums.empty())
        {
            sum += nums.top();
            nums.pop();
        }
        return sum;
    }
};
// @lc code=end

#if 0
class Solution
{
public:
    int calculate(string s)
    {
        int sum = 0;
        int temp = 0;
        int pre = 0;
        char sign = '+';
        stack<int> nums;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
                temp = (temp * 10 + (s[i] - '0'));

            // if (s[i] == '(')
            // {
            //     temp = calculate(s.substr(i+1));
            // }
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.length() - 1)
            {
                switch (sign)
                {
                case '+':
                    nums.push(temp); break;
                case '-':
                    nums.push(-temp); break;
                case '*':
                    pre = nums.top();
                    nums.pop();
                    nums.push(pre * temp);
                    break;
                case '/':
                    pre = nums.top();
                    nums.pop();
                    nums.push(pre / temp);
                    break;
                default:
                    break;
                }

                temp = 0;
                sign = s[i];
            }
            // if (s[i] == ')')
            // {
            //     break;
            // }
        }
        while (!nums.empty())
        {
            sum += nums.top();
            nums.pop();
        }
        return sum;
    }
};
#endif
