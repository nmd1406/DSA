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
        int arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        int dp[n]{};
        
        int ans{};
        for(int i{}; i < n; ++i)
        {
            dp[i] = arr[i];

            for(int j{}; j < i; ++j)
            {
                if(arr[j] < arr[i])
                    dp[i] = max(dp[i], dp[j] + arr[i]);
            }

            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}