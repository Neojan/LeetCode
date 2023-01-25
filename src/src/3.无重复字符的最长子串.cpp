/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int                      left = 0, right = 0;
        int                      res = 0;
        while(right < s.length())
        {
            char c = s[right];
            right++;
            window[c]++;
            
            while(window[c] > 1)
            {
                char d = s[left];
                left++;
                window[d]--;
            }
            res = (right - left) > res ? (right - left) : res;
        }
        return res;
    }
};
// @lc code=end

