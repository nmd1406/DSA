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

int postFixEval(const string& str)
{
    stack<int> s{};

    int n = str.length();
    for(int i{}; i < n; ++i)
    {
        if(isOperator(str[i]))
        {
            int op1{s.top()};
            s.pop();
            int op2{s.top()};
            s.pop();

            switch(str[i])
            {
                case '+':
                    s.push(op2 + op1);
                    break;
                case '-':
                    s.push(op2 - op1);
                    break;
                case '*':
                    s.push(op2 * op1);
                    break;
                case '/':
                    s.push(op2 / op1);
                    break;
            }
        }
        else
            s.push(str[i] - '0');
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

        cout << postFixEval(str) << '\n';
    }

    return 0;
}