#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        queue<int> q{};
        while(n--)
        {
            int opt{};
            cin >> opt;

            if(opt == 1)
                cout << q.size() << '\n';
            else if(opt == 2)
            {
                if(q.empty())
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else if(opt == 3)
            {
                int num{};
                cin >> num;
                q.push(num);
            }
            else if(opt == 4)
            {
                if(!q.empty())
                    q.pop();
            }
            else if(opt == 5)
            {
                if(!q.empty())
                    cout << q.front() << '\n';
                else
                    cout << "-1\n";
            }
            else
            {
                if(!q.empty())
                    cout << q.back() << '\n';
                else
                    cout << "-1\n";
            }
        }
    }

    return 0;
}