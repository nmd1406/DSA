#include<bits/stdc++.h>

using namespace std;

int solve(double a[], double b[], int n)
{
    int dp[n + 1]{};
    dp[1] = 1;

    int res{};
    for(int i{}; i < n; ++i)
    {
        dp[i] = 1;

        for(int j{0}; j < i; ++j)
        {
            if(a[j] < a[i] && b[j] > b[i])
                dp[i] = max(dp[i], dp[j] + 1);            
        }

        res = max(res, dp[i]);
    }

    return res;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        double a[n + 1]{};
        double b[n + 1]{};

        for(int i{}; i < n; ++i)
            cin >> a[i] >> b[i];

        cout << solve(a, b, n) << '\n';
    }

    return 0;
}