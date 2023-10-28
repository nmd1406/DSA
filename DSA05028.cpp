#include<bits/stdc++.h>

using namespace std;

int bienDoi(const string& str1, const string& str2)
{
    int m = str1.size();
    int n = str2.size();
    int dp[m + 1][n + 1];

    for(int i{}; i <= m; ++i)
    {
        for(int j{}; j <= n; ++j)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
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

        cout << bienDoi(str1, str2) << '\n';
    }

    return 0;
}