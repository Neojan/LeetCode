#if 0
题目描述
某多处理器多道批处理系统一次允许将多有作业调入内存，且能并行执行，其并行数等于处理器个数。该系统采用SJF的调度方式（最短作业优先，系统在调度时，总是有限调度执行处理时间最短的作业）。
现给定处理器个数m，作业数n，每个作业的处理时间分别为t1, t2... tn.当n > m时，首先处理时间短的m个作业进入处理器处理，其他进入等待，当某个作业处理完成时，依次从等待队列中取处理时间最短的作业进入处理。 求系统处理完所有作业的耗时为多少？ 注：不考虑作业切换的消耗。

输入描述： 输入2行，第一行为2个整数（采用空格分隔），分别表示处理器个数m和作业数n；第二行输入n个整数（采用空格分隔），表示每个作业的处理时长t1,
t2... tn。0 < m, n < 100, 0 < t1, t2... tn < 100。

输出描述： 输出处理总时长

示例1 输入 3 5 8 4 3 1 10

输出 13

说明 首先，执行时长为1、3、4的作业4（cpu1）、作业3（cpu2）、作业2（cpu3）进入处理。 1个时间单元后，作业4执行结束，作业1进入处理（cpu1）； 3个时间单元后，作业3执行结束，作业5进入处理（cpu1）； 4个时间单元后，作业2执行结束； 9个时间单元后，作业1执行结束； 13个时间单元后，作业5执行结束。
#endif

// 1 3 4 8 10
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;

    while (cin >> m >> n)
    {
        int         input;
        vector<int> time;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            time.push_back(input);
        }

        sort(time.begin(), time.end());

        int len   = time.size();
        int index = len % m - 1;
        int res   = 0;
        for (int i = index; i < len; i = i + m)
        {
            res += time[i];
        }

        cout << res << endl;
    }
#if 0
    int m, n;
    std::cin >> m >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    int rows = (n % m) == 0 ? (n / m) : (n / m) + 1;    // 获取任务行数
    int remainder = (n % m) == 0 ? m - 1 : (n % m) - 1; // 获取最后执行完任务的一列
    int max_time = 0;
    for (int i = 0; i < rows; ++i) {
        max_time += v[i * m + remainder];
    }
 
    std::cout << max_time << std::endl;
#endif
    return 0;
}