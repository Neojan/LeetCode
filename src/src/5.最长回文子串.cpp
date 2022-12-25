/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string palindrome(string s, int l, int r)
    {
        while (l >= 0 && r<s.length()&&s[l]==s[r])
        {
            --l;
            ++r;
        }
        return s.substr(l+1, r -l-1);
    }

    string longestPalindrome(string s) {
        string maxS = "";
        for (int i = 0; i < s.length(); i++)
        {
            string temp = palindrome(s, i, i);//奇数长
            maxS        = temp.length() > maxS.length() ? temp : maxS;
            temp        = palindrome(s, i, i+1); //偶数长
            maxS        = temp.length() > maxS.length() ? temp : maxS;
        }
        return maxS;
    }
};
// @lc code=end

