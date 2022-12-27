/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t)
            need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        // 记录最⼩覆盖⼦串的起始索引及⻓度
        int start = 0, len = INT_MAX;
        while (right < s.size())
        {
            // c 是将移⼊窗⼝的字符
            char c = s[right];
            // 扩⼤窗⼝
            right++;
            // 进⾏窗⼝内数据的⼀系列更新
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            // 判断左侧窗⼝是否要收缩
            while (valid == need.size())
            {
                // 在这⾥更新最⼩覆盖⼦串
                if (right - left < len)
                {
                    start = left;
                    len   = right - left;
                }
                // d 是将移出窗⼝的字符
                char d = s[left];
                // 缩⼩窗⼝
                left++;
                // 进⾏窗⼝内数据的⼀系列更新
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        // 返回最⼩覆盖⼦串
        return len == INT_MAX ?
                   "" :
                   s.substr(start, len);
    }
};
// @lc code=end

