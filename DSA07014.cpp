#include<bits/stdc++.h>

using namespace std;

int prefixEval(string& str)
{
    stack<int> s{};
    int n = str.length();

    for(int i{n - 1}; i >= 0; --i)
    {
        if(isdigit(str[i]))
            s.push(str[i] - '0');
        else
        {
            int op1{s.top()};
            s.pop();
            int op2{s.top()};
            s.pop();

            switch(str[i])
            {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
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

        cout << prefixEval(str) << '\n';
    }

    return 0;
}