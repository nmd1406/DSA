#include<bits/stdc++.h>

using namespace std;

int solve(int arr[], int n)
{
    int dp[n + 1]{};
    dp[0] = 0;
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);

    for(int i{3}; i <= n; ++i)
        dp[i] = max(dp[i - 2] + arr[i - 1], dp[i - 1]);
    
    return dp[n];
}

int main()
{
    int test{};
    cin >> test;
    
    while(test--)
    {
        int n{};
        cin >> n;
        int arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        cout << solve(arr, n) << '\n';
    }
    return 0;
}