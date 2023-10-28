#include<bits/stdc++.h>

using namespace std;

int nCr(int n, int k)
{
    int mod = 1e9 + 7;
    int dp[n + 1][k + 1]{};

    for(int i{}; i <= n; ++i)
    {
        for(int j{}; j <= min(i, k); ++j)
        {
            if(j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
        }
    }

    return dp[n][k];
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

        cout << nCr(n, k) << '\n';
    }

    return 0;
}