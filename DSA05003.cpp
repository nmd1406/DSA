#include<bits/stdc++.h>

using namespace std;

int solve(string& str1, string& str2, string& str3)
{
    int l1 = str1.length();
    int l2 = str2.length();
    int l3 = str3.length();

    int dp[l1 + 1][l2 + 1][l3 + 1]{};

    for(int i{}; i <= l1; ++i)
    {
        for(int j{}; j <= l2; ++j)
        {
            for(int k{}; k <= l3; ++k)
            {
                if(i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if(str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }

    return dp[l1][l2][l3];
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int x{};
        int y{};
        int z{};
        cin >> x >> y >> z;

        string str1{};
        string str2{};
        string str3{};
        cin >> str1 >> str2 >> str3;

        cout << solve(str1, str2, str3) << '\n';
    }

    return 0;
}