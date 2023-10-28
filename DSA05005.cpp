#include<bits/stdc++.h>

using namespace std;

int dayCon(int arr[], int n)
{
    int dp[n]{};

    int res{};
    for(int i{}; i < n; ++i)
    {
        dp[i] = 1;

        for(int j{}; j < i; ++j)
        {
            if(arr[j] <= arr[i])
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
        int arr[n]{};

        for(int i{}; i < n; ++i)
            cin >> arr[i];

        cout << n - dayCon(arr, n) << '\n';
    }

    return 0;
}