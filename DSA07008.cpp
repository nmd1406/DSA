#include<bits/stdc++.h>

using namespace std;

int prio(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 3;

    return -1;
}

string infixToPostfix(string& str)
{
    stack<char> s{};
    int n = str.length();

    string res{};

    for(int i{}; i < n; ++i)
    {
        if(str[i] == '(')
            s.push(str[i]);
        else if(isalpha(str[i]))
            res += str[i];
        else if(str[i] == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                char ch{s.top()};
                s.pop();

                res += ch;
            }

            if(s.top() == '(')
                s.pop();
        }
        else
        {
            while(!s.empty() && prio(str[i]) <= prio(s.top()))
            {
                char ch{s.top()};
                s.pop();
                res += ch;
            }

            s.push(str[i]);
        }
    }

    while(!s.empty() && s.top() != '(')
    {
        char ch{s.top()};
        s.pop();
        res += ch;
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

        cout << infixToPostfix(str) << '\n';
    }
    return 0;
}