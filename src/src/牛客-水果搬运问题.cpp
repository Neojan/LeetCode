
#include <iostream>
#include <queue>

using namespace std;
int main(void)
{
    int                                            n   = 0; //水果堆数量
    int                                            en  = 0; //每堆水果的数量
    int                                            res = 0; //总消耗体力
    priority_queue<int, vector<int>, greater<int>> pq;
    while (cin >> n)
    {
        while (!pq.empty())
        {
            pq.pop();
        }
        for (int i = 0; i < n; i++)
        {
            cin >> en;
            pq.push(en);
        }
        while (pq.size() > 1)
        {
            int q1 = pq.top();
            pq.pop();
            int q2 = pq.top();
            pq.pop();
            res += q1 + q2;
            pq.push(res);
        }
        cout << res << endl;
    }
    return 0;
}