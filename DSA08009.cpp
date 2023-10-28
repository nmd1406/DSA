#include<bits/stdc++.h>

using namespace std;

int solve(int s, int t)
{
    int dp[20001]{};
    queue<int> q{};
    q.push(s);

    while(!dp[t])
    {
        int temp{q.front()};
        q.pop();

        if(temp - 1 > 0 && !dp[temp - 1])
        {
            dp[temp - 1] = dp[temp] + 1;
            q.push(temp - 1);
        }   

        if(temp * 2 < 20000 && !dp[temp * 2])
        {
            dp[temp * 2] = dp[temp] + 1;
            q.push(temp * 2);
        }
    }

    return dp[t];
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int s{};
        int t{};
        cin >> s >> t;

        cout << solve(s, t) << '\n';
    }

    return 0;
}