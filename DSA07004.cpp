#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        string str{};
        cin >> str;

        int count{};
        stack<char> s{};

        for(int i{}; i < str.length(); ++i)
        {
            if(str[i] == '(')
                s.push(str[i]);
            else
            {
                if(!s.empty())
                    s.pop();
                else
                {
                    ++count;
                    s.push('(');
                }
            }
        }

        cout << s.size() / 2 + count << '\n';
    }

    return 0;
}