
#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    string input, cur, res;
    while (cin >> input)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                cur.push_back(input[i]);
            }
            else
            {
                res = (res.length() > cur.length()) ? res : cur;
                cur = "";
            }
        }
        cout << res << endl;
    }
    return 0;
}