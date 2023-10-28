#include<bits/stdc++.h>

using namespace std;

int longestSubStr(const string& str1, const string& str2)
{
    int m = str1.size();
    int n = str2.size();

    int dp[m + 1][n + 1];
    for(int i{}; i <= m; ++i)
    {
        for(int j{}; j <= n; ++j)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        string str1{};
        string str2{};
        cin >> str1 >> str2;

        cout << longestSubStr(str1, str2) << '\n';
    }

    return 0;
}