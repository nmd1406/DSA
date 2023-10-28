#include<bits/stdc++.h>

using namespace std;

bool isOperator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }

    return false;
}

string prefixToPostFix(const string& str)
{
    stack<string> s{};

    for(int i = str.size() - 1; i >= 0; --i)
    {
        if(isOperator(str[i]))
        {
            string op1{s.top()};
            s.pop();
            string op2{s.top()};
            s.pop();

            string temp{op1 + op2 + str[i]};
            s.push(temp);
        }
        else
            s.push(string(1, str[i]));
    }

    return s.top();
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        string str{};
        cin >> str;

        cout << prefixToPostFix(str) << '\n';
    }

    return 0;
}