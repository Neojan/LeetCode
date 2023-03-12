
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;
int main(void)
{
    int L = 0; //独木桥长度
    int S = 0;//最小跳跃距离
    int T = 0; //最大跳跃距离
    int M = 0;//石头个数
    unordered_map <int, int> stoneDic;
    vector<int>                 dp(INT_MAX, 0);//最小石头个数, dp[0]=0,表示距离0踩到的石头个数是0
    cin >> L;
    
    while (cin >> S >> T >> M)
    {  
        for (int i = 1; i <= M; i++)
        {
            stoneDic[i]++;
        }
        for (int i = 1; i <= L; i++)
        {
            for (int j = S; j <= T; j++)
            {
                if (i-j<0)
                    break;
                if (stoneDic[i]) //当前距离刚好有石头
                {
                    dp[i] = min(dp[i - 1], dp[i - j] + 1);
                }
                else
                {
                    dp[i] = min(dp[i], dp[i-j]);
                }
            }
        }
        
    }
    return 0;
}

