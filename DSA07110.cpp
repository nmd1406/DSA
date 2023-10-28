#include<bits/stdc++.h>

using namespace std;

bool isValid(const string& str)
{
    stack<char> s{};
    for(char ch : str)
    {
        if(ch == '[' || ch == '(' || ch == '{')
            s.push(ch);
        else
        {
            if(s.empty())
                return false;
            else if(ch == ']')
            {
                if(s.top() == '[')
                    s.pop();
                else
                    return false;
            }
            else if(ch == ')')
            {
                if(s.top() == '(')
                    s.pop();
                else
                    return false;
            }
            else
            {
                if(s.top() == '{')
                    s.pop();
                else
                    return false;
            }
        }
    }

    if(s.empty())
        return true;
    
    return false;
}

int main()
{
    int test{};
        
    cin >> test;

    while(test--)
    {
        string str{};
        cin >> str;

        if(isValid(str))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}