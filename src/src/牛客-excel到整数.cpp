#if 0
一个正整数到 Excel 编号之间的转换
题目描述：完成从一个正整数到 Excel 编号之间的转换。
用过 excel 的都知道 excel 的列编号是这样的：
abc…z
aaabac…az
babbbc…yzzazbzc…zzaaaaabaac…
分别代表以下编号：
123…26
272829…52
535455…676677678679…702703704705…请写个函数，
完成从一个正整数到这种字符串之间的转换。
原型：intTranslate(intN, string & ans)
功能:正整数到 Excel 编号字符串转换
输入 : N
输出 : ans
返回 : 0
#endif

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int intTrans(int N, string &ans)
{
    if (N <= 0)
        return -1;
    ans = "";
    while (N > 0)
    {
        N -= 1;
        ans += ((N % 26) + 'a');
        N /= 26;
    }
    reverse(ans.begin(), ans.end());
    return 0;
}
int main()
{
    int N;
    cin >> N;
    string ans;
    intTrans(N, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    return 0;
}
