#include<bits/stdc++.h>

using namespace std;

bool isValid(string& str)
{
    stack<int> s{};
    
    int n = str.length();

    for(int i{}; i < n; ++i)
    {
        if(str[i] == '(')
            s.push(i);
        else if(str[i] == ')')
        {
            int j{s.top()};
            s.pop();
            if(i - j == 2)
                return true;
            if(str[i - 1] == ')' && str[j + 1] == '(')
                return true;
        }
    }

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
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}