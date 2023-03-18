#if 0
小王手里有点闲钱，想着做点卖水果的小买卖，给出两个数组m，n，用m[i]表示第i个水果的成本价，
n[i]表示第i个水果能卖出的价钱，假如现在有本钱k元，试问最后最多能赚多少钱？

说明：
1. 每种水果只能买一次，只能卖一次；
2. 数组m,n大小不超过50；
3. 数组元素为正整数，不超过1000

输入描述
1. 数组m, n;
2. 本钱k

输出描述
最多能赚多少钱
示例

输入：
4,2,6,4
5,3,8,7
15

输出：
22
#endif
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

//可以用priority_queue实现简单
typedef struct ProductInfo
{
    int cost;
    int profit;
    int isbuy = 0;
} ProductInfo;

vector<int> StringToVector(const string &str)
{
    stringstream sstream(str);
    string       token = "";
    vector<int>  vec_str;
    vec_str.clear();
    while (getline(sstream, token, ','))
    {
        int num = 0;
        for (int i = 0; i < token.size(); i++)
        {
            num = 10 * num + token[i] - '0';
        }
        vec_str.push_back(num);
    }
    return vec_str;
}
bool Compare(const ProductInfo &a, const ProductInfo &b)
{
    return a.profit > b.profit;
}
bool CheckInfo(vector<ProductInfo> &productinfos, int cost_k)
{
    bool flag = false;
    for (int i = 0; i < productinfos.size(); i++)
    {
        if (productinfos[i].isbuy == 1)
        {
            continue;
        }
        if (productinfos[i].profit < 0)
        {
            continue;
        }
        if (productinfos[i].cost < cost_k)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
int main()
{
    string m = "";
    while (getline(cin, m))
    {
        if (m.empty())
        {
            break;
        }
        string n = "";
        getline(cin, n);
        int k;
        cin >> k;
        vector<int>         vec_m = StringToVector(m);
        vector<int>         vec_n = StringToVector(n);
        vector<ProductInfo> productinfos;
        productinfos.clear();
        for (int i = 0; i < vec_m.size(); i++)
        {
            ProductInfo productinfo;
            productinfo.cost   = vec_m[i];
            productinfo.profit = vec_n[i] - vec_m[i];
            if (productinfo.profit <= 0)
            {
                continue;
            }
            productinfo.isbuy = 0;
            productinfos.push_back(productinfo);
        }
        sort(productinfos.begin(), productinfos.end(), Compare);
        int cost_k = k;
        while (CheckInfo(productinfos, cost_k))
        {
            for (int i = 0; i < productinfos.size(); i++)
            {
                if (productinfos[i].cost > cost_k)
                {
                    continue;
                }
                if (productinfos[i].profit <= 0)
                {
                    continue;
                }
                if (productinfos[i].isbuy == 1)
                {
                    continue;
                }
                cost_k += productinfos[i].profit;
                productinfos[i].isbuy = 1;
            }
        }
        cout << cost_k << endl;
    }
    return 0;
}