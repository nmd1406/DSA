#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;

    queue<int> q;
    while(n--)
    {
        string str{};
        cin >> str;

        if(str == "PUSH")
        {
            int num{};
            cin >> num;
            q.push(num);
        }
        else if(str == "POP" && !q.empty())
            q.pop();
        else if(str == "PRINTFRONT")
        {
            if(q.empty())
                cout << "NONE\n";
            else
                cout << q.front() << '\n';
        }
    }

    return 0;
}