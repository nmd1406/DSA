#include<bits/stdc++.h>

using namespace std;

int solve(int arr[], int n, int k)
{
    const int mod = 1e9 + 7;
    int dp[k + 1]{};

    dp[0] = 1;

    for(int i{1}; i <= k; ++i)
    {
        for(int j{1}; j <= n; ++j)
        {
            if(arr[j] <= i)
                dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
        }
    }

    return dp[k];
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

        int arr[n + 1]{};
        for(int i{1}; i <= n; ++i)
            cin >> arr[i];
        
        cout << solve(arr, n, k) << '\n';
    }

    return 0;
}