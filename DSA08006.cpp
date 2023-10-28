#include<bits/stdc++.h>

using namespace std;

void solve(int n)
{
    queue<int> q{};
    q.push(9);

    while(!q.empty())
    {
        int x{q.front()};
        q.pop();

        if(x % n == 0)
        {
            cout << x << '\n';
            break;
        }

        q.push(x * 10);
        q.push(x * 10 + 9);
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        solve(n);
    }


    return 0;
}