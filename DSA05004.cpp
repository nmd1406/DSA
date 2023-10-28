#include<bits/stdc++.h>

using namespace std;

int dayCon(int arr[], int n)
{
    int res{};
    int dp[n + 1]{};
    dp[0] = 0;
    dp[1] = 1;

    for(int i{2}; i <= n; ++i)
    {
        dp[i] = 1;
        
        for(int j{1}; j < i; ++j)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i] , dp[j] + 1);
        }

        res = max(res, dp[i]);
    }

    return res;
}

int main()
{
    int n{};
    cin >> n;
    int arr[n + 1]{};
    for(int i{1}; i <= n; ++i)
        cin >> arr[i];
    cout << dayCon(arr, n) << '\n';

    return 0;
}