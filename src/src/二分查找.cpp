#include <iostream>
#include <vector>

using namespace std;

// 寻找一个值
int binary_search(vector <int> s, int d)
{
    int mid = 0, left = 0, right = s.size()-1;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if (s[mid] < d)
        {
            left = mid + 1;
        }
        else if (s[mid] > d)
        {
            right = mid - 1;
        }
        else if (s[mid] == d)
        {
            return mid;
        }
    }
    return -1;
}

// 寻中左边界
int binary_search_left_bound(vector<int> s, int d)
{
    int mid = 0, left = 0, right = s.size() - 1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (s[mid] < d)
        {
            left = mid + 1;
        }
        else if (s[mid] > d)
        {
            right = mid - 1;
        }
        else if (s[mid] == d)
        {
            right = mid - 1;
        }
    }
    cout << left << "," << s.size()<< endl;
    if (left == s.size())
        return -1;
    
    return s[left]==d ? left : -1;
}

// 寻中右边界
int binary_search_right_bound(vector<int> s, int d)
{
    int mid = 0, left = 0, right = s.size() - 1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (s[mid] < d)
        {
            left = mid + 1;
        }
        else if (s[mid] > d)
        {
            right = mid - 1;
        }
        else if (s[mid] == d)
        {
            left = mid + 1;
        }
    }
    cout << left << "," << s.size() << endl;
    if (left -1 < 0)
        return -1;

    return s[left - 1] == d ? (left - 1) : -1;
}

int main(void)
{
    vector<int> s1{0,1,2,3,4,5,6,7};
    int pos = binary_search(s1, 3);
    vector<int> s2{1, 2, 3, 3, 3, 4, 6, 7};

    pos = binary_search_left_bound(s2, 0);
    pos = binary_search_left_bound(s2, 1);
    pos = binary_search_left_bound(s2, 8);
    pos = binary_search_left_bound(s2, 3);
    pos = binary_search_right_bound(s2, 3);
    pos = binary_search_right_bound(s2, 1);
    cout << pos << endl;

    return 0;
}