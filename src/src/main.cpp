#include <iostream>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int                      right = 0;
        int                      left  = 0;
        int                      valid = 0;
        int                      start = 0;
        int                      len   = INT_MAX;

        for (char c : t)
            need[c]++;
        while (right < s.size())
        {
            char d = s[right];
            right++;
            if (need.count(d))
            {
                // 字符被找到
                window[d]++;
                if (window[d] == need[d])
                {
                    valid++;
                }
            }
            while (valid == need.size())
            {
                std::cout << left << "," << right  << std::endl;
                if (right - left < len)
                {
                    start = left;
                    len   = right - left;
                }
                char e = s[left];
                left++;
                if (need.count(e))
                {
                    //如果要移除的是需要的，且个数也是符合
                    if (need[e] == window[e])
                    {
                        valid--;
                    }
                    window[e]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
int main(void)
{
    Solution a;
    string   s1 = "ADOBECODEBANC";
    string   s2 = "ABC";

    string s3 = a.minWindow(s1, s2);
    std::cout << s3 << std::endl;
    string testStr = "123456";
    std::cout << testStr.size() << ", " << testStr.length() << std::endl;
    unordered_set<int> testSet = {1,2,3,4,4};
    std::cout << testSet.size() << std::endl;
    return 0;
}