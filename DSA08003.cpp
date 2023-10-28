#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;

    deque<int> q;
    while(n--)
    {
        string str;
        cin >> str;

        if(str == "PUSHBACK")
        {
            int num;
            cin >> num;
            q.push_back(num);
        }
        else if(str == "PUSHFRONT")
        {
            int num;
            cin >> num;
            q.push_front(num);
        }
        else if(str == "POPFRONT" && !q.empty())
            q.pop_front();
        else if(str == "PRINTFRONT")
        {
            if(q.empty())
                cout << "NONE\n";
            else
                cout << q.front() << '\n';
        }
        else if(str == "PRINTBACK")
        {
            if(q.empty())
                cout << "NONE\n";
            else
                cout << q.back() << '\n';
        }
        else if(str == "POPBACK" && !q.empty())
            q.pop_back();
    }

    return 0;
}