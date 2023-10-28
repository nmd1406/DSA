#include<bits/stdc++.h>

using namespace std;

int solve(const string& str)
{
    int n = str.length();
    int dp[n + 1][n + 1]{};

    for(int i{n - 2}; i >= 0; --i)
    {
        for(int j{i + 1}; j < n; ++j)
        {
            if(str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        string str{};
        cin >> str;

        cout << solve(str) << '\n';
    }

    return 0;
}