
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;
int main(void)
{
    int                     L    = 0; //独木桥长度
    int                     S    = 0; //最小跳跃距离
    int                     T    = 0; //最大跳跃距离
    int                     M    = 0; //石头个数
    int                     temp = 0;
    unordered_map<int, int> stoneDic;
    cin >> L;
    vector<int> dp(L + 1, INT_MAX); //最小石头个数, dp[0]=0,表示距离0踩到的石头个数是0
    dp[0] = 0;
    dp[1] = 1;
    cin >> S >> T >> M;
    {
        // cout << S << T << M << endl;
        for (int i = 1; i <= M; i++)
        {
            cin >> temp;
            stoneDic[temp]++;
        }
        stoneDic[L]++;
        for (int i = 1; i <= L; i++)
        {
            for (int j = S; j <= T; j++)
            {
                if (i - j >= 0)
                {
                    cout << i << "," << j << "," << stoneDic[i] << "," << dp[i] << "," << dp[i - j] << endl;
                    dp[i] = min(dp[i], dp[i - j] + stoneDic[i]);
                }
            }
        }
        cout << dp[L] << endl;
    }
    return 0;
}
