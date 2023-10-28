#include<iostream>

using namespace std;

int solve(int n, int x, int y, int z)
{
    int dp[n + 1]{};
    dp[1] = x;
    for(int i{2}; i <= n; ++i)
    {
        if(i % 2 == 0)
            dp[i] = min(dp[i - 1] + x, dp[i / 2] + z);
        else
            dp[i] = min(dp[i - 1] + x, dp[(i + 1) / 2] + y + z);
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
        int x{};
        int y{};
        int z{};
        cin >> n >> x >> y >> z;

        cout << solve(n, x, y, z) << '\n';
    }

    return 0;
}