#if 0
免单统计 
题目描述 
某商城举办了一个促销活动，如果某顾客是某一秒内第一个下单的顾客（可能是多个人），则可以 获取免单。请你编程计算有多少顾客可以获取免单。
解答要求 时间限制：3000ms, 内存限制：64MB ，输入： 输入为n行数据，每一行表示一位顾客的下单时 间。 以（年-月-日 时-分-秒.毫秒）yyyy-MM-dd HH:mm:ss.ﬀf形式给出。

0<n<50000 2000<yyyy<2020 0<MM<=12 0<dd<=28 0<=HH<=23 0<=mm<=59 0<=ss<=59 0<=ﬀf<=999 所有输 入保证合法。
输出 输出一个整数，表示有多少顾客可以获取免单。
样例：
输入样例1
2019-01-01 00:00:00.001 
2019-01-01 00:00:00.002 
2019-01-01 00:00:00.003
输出样例1 
1 

输入样例2
2019-01-01 08:59:00.123 
2019-01-01 08:59:00.123
2018-12-28 10:08:00.999 
输出样例2 
3
#endif

#include <iostream>
#include <time.h>
#include <map>
#include <string>

#include <iostream>
#include <map>

using namespace std;

struct FirstOrder
{
    int microSecond;
    int count;
};

string getFirstPartTime(string timeStr)
{
    size_t n = timeStr.find_first_of('.');
    string firstPart(timeStr.c_str(), timeStr.c_str() + n);
    return firstPart;
}

int getSecondPartTime(string timeStr)
{
    size_t n = timeStr.find_first_of('.');
    n++;
    return atoi(timeStr.c_str() + n);
}

int main(int argc, char **argv)
{
    string                  line;
    map<string, FirstOrder> staticsMap;
    // 记录 每秒钟第一个下单的人数
    while (getline(cin, line))
    {
        string                            s  = getFirstPartTime(line);
        int                               ms = getSecondPartTime(line);
        map<string, FirstOrder>::iterator it = staticsMap.find(s);
        if (it != staticsMap.end()) // 在 map 中已经存在，需要更新
        {

            if (ms < it->second.microSecond)
            {
                it->second.microSecond = ms;
                it->second.count       = 1;
            }
            else if (ms == it->second.microSecond)
            {
                it->second.count++;
            }
        }
        else // 不存在，需要插入
        {
            FirstOrder order;
            order.microSecond = ms;
            order.count       = 1;
            staticsMap.insert(make_pair(s, order));
        }
    }

    // 统计所有第一个下单的人数
    size_t                            freeOrderNum = 0;
    map<string, FirstOrder>::iterator it           = staticsMap.begin();
    while (it != staticsMap.end())
    {
        freeOrderNum += it->second.count;
        it++;
    }
    cout << freeOrderNum << endl;
}