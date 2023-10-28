#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;

    int arr[n]{};
    for(int i{}; i < n; ++i)
        cin >> arr[i];

    int dp[n + 1]{};
    dp[1] = 1;

    int lis{};
    for(int i{2}; i < n; ++i)
    {
        dp[i] = 1;
        for(int j{}; j < i; ++j)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        lis = max(lis, dp[i]);
    }

    cout << n - lis;

    return 0;
}