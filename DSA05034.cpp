#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long bacThang(int n, int k)
{
    long long dp[n + 1]{};
    dp[0] = 1;
    dp[1] = 1;

    for(int i{2}; i <= n; ++i)
    {
        for(int j{1}; j <= k; ++j)
        {
            if(i - j >= 0)
            {
                dp[i] += dp[i - j]; 
                dp[i] %= mod;
            }
        }
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

        cout << bacThang(n, k) << '\n';
    }

    return 0;
}