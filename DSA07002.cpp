#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;
    stack<int> s{};

    while(n--)
    {
        string cmd{};
        cin >> cmd;
        int num{};
        if(cmd == "PUSH")
        {
            cin >> num;
            s.push(num);
        }
        else if(cmd == "POP" && !s.empty())
            s.pop();
        else if(cmd == "PRINT")
        {
            if(s.empty())
                cout << "NONE" << '\n';
            else
                cout << s.top() << '\n';
        }
    }

    return 0;
}