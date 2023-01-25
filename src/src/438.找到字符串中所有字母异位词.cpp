/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> need, window;
        vector<int>              res;
        int                      left  = 0;
        int                      right = 0;
        int                      valid = 0;
        for (char i : p)
        {
            need[i]++;
        }
        while (right < s.length())
        {
            char c = s[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                {
                    valid++;
                }
            }
            while (right - left >= p.size())
            {
                if (valid == need.size())
                {
                    res.push_back(left);
                }
                char lc = s[left];
                left++;
                if (need.count(lc))
                {
                    if (window[lc] == need[lc])
                    {
                        valid--;
                    }
                    window[lc]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
