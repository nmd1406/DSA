#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long climbStair(int n, int k)
{
    long long* dp{new long long[n + 1]{}};
    dp[0] = 1;
    dp[1] = 1;

    for(int i{2}; i <= n; ++i)
    {
        long long ans{};
        for(int j{1}; j <= k; ++j)
        {
            if(i - j >= 0)
                ans = (ans + dp[i - j]) % mod;
        }

        dp[i] = ans;
    }

    return dp[n];
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int k{};
        cin >> n >> k;

        cout << climbStair(n, k) << '\n';
    }

    return 0;
}