#include<bits/stdc++.h>

using namespace std;

int solve(string& str)
{
    int n = str.length();
    int ans{INT_MIN};

    bool dp[n + 1][n + 1]{};

    for(int i{n - 1}; i >= 0; --i)
    {
        for(int j{i}; j <= n - 1; ++j)
        {
            if(i == j)
                dp[i][j] = true;
            else if(str[i] == str[j])
            {
                if(j - i == 1)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }

            if(dp[i][j])
                ans = max(ans, j - i + 1);
        }
    }

    return ans;
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