#include<bits/stdc++.h>

using namespace std;

int solve(string& str)
{
    stack<int> s{};
    s.push(-1);

    int n = str.length();
    int res{};
    for(int i{}; i < n; ++i)
    {
        if(str[i] == '(')
            s.push(i);
        else
        {
            s.pop();
            if(!s.empty())
            {
                int j{s.top()};
                res = max(res, i - j);
            }
            else
                s.push(i);
        }
    }

    return res;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        string str{};
        cin >> str;

        cout << solve(str) << '\n';
    }

    return 0;
}