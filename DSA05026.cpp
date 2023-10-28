#include<bits/stdc++.h>

using namespace std;

int bo(int n, int w[], int c)
{
    int dp[n + 1][c + 1]{};

    for(int i{1}; i <= n; ++i)
    {
        for(int j{1}; j <= c; ++j)
        {
            if(w[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j - w[i - 1]] + w[i - 1], dp[i - 1][j]);
        }
    }

    return dp[n][c];
}

int main()
{
    int c{};
    int n{};
    cin >> c >> n;

    int w[n]{};
    for(int i{}; i < n; ++i)
        cin >> w[i];

    cout << bo(n, w, c) << '\n';

    return 0;
}