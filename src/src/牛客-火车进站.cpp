#include <stack>
#include <iostream>

using namespace std;
int n, a[15], c[15];

//根据入栈序列判断出栈序列是否正确
bool check(int b[])
{
    stack<int> st; //栈
    int        j = 0;
    for (int i = 0; i < n; i++)
    { //遍历入栈序列
        st.push(a[i]);
        while (!st.empty() && b[j] == st.top())
        { //如果栈顶元素等于出栈序列元素，则栈顶元素出栈并出栈序列下标加一
            st.pop();
            j++;
        }
    }
    return st.empty(); //判断栈是否为空
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        { //输入入栈序列
            cin >> a[i];
            c[i] = a[i];
        }
        //排序
        sort(c, c + n);
        //全排列出栈序列
        do
        {
            if (check(c))
            { //如果成功，则输出该出栈序列
                for (int i = 0; i < n; i++)
                {
                    cout << c[i] << " ";
                }
                cout << endl;
            }
        } while (next_permutation(c, c + n));
    }
    return 0;
}