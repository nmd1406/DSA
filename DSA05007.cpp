#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        int arr[n + 1]{};
        for(int i{1}; i <= n; ++i)
            cin >> arr[i];

        int dp[n + 1]{};
        dp[1] = arr[1];
        dp[2] = max(arr[1], arr[2]);

        for(int i{3}; i <= n; ++i)
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);

        cout << dp[n] << '\n';
    }

    return 0;
}