#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> s{};
    string cmd{};

    while(cin >> cmd)
    {
        int num{};
        if(cmd == "push")
        {
            cin >> num;
            s.push(num);
        }
        else if(cmd == "pop" && !cmd.empty())
            s.pop();
        else
        {
            if(s.empty())
                cout << "empty" << '\n';
            else
            {
                stack<int> temp{};
                while(!s.empty())
                {
                    temp.push(s.top());
                    s.pop();
                }

                while(!temp.empty())
                {
                    cout << temp.top() << ' ';
                    s.push(temp.top());
                    temp.pop();
                }    

                cout << '\n';
            }

        }
    }

    return 0;
}