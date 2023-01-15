/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int                      valid = 0;
        for (char c : s1)
            need[c]++;
        int right = 0;
        int left  = 0;
        while (right < s2.size())
        {
            char d = s2[right];
            right++;
            if (need.count(d))
            {
                window[d]++;
                if (window[d] == need[d])
                {
                    valid++;
                }
            }

            while (right - left >= s1.length())
            {
                if (valid == need.size())
                    return true;
                char d = s2[left];
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
                left++;
            }
        }
        return false;
    }
};
// @lc code=end

