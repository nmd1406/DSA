#include<bits/stdc++.h>

using namespace std;

bool isOp(char ch)
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

string prefixToInfix(string& str)
{
    stack<string> s{};

    int n = str.length();
    for(int i{n - 1}; i >= 0; --i)
    {
        if(isOp(str[i]))
        {
            string operand1{s.top()};
            s.pop();
            string operand2{s.top()};
            s.pop();

            string temp{"(" + operand1 + str[i] + operand2 + ")"};
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

        cout << prefixToInfix(str) << '\n';
    }

    return 0;
}