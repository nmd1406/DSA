#include<bits/stdc++.h>

using namespace std;

int solve(int arr[], int n)
{
    int dec[n]{};
    int inc[n]{};

    for(int i{}; i < n; ++i)
    {
        inc[i] = arr[i];
        for(int j{}; j < i; ++j)
        {
            if(arr[j] < arr[i])
                inc[i] = max(inc[i], inc[j] + arr[i]);
        }
    }

    for(int i{n - 1}; i >= 0; --i)
    {
        dec[i] = arr[i];
        for(int j{n - 1}; j > i; --j)
        {
            if(arr[j] < arr[i])
                dec[i] = max(dec[i], dec[j] + arr[i]);
        }
    }

    int ans{dec[0] + inc[0] - arr[0]};
    for(int i{1}; i < n; ++i)
        ans = max(ans, dec[i] + inc[i] - arr[i]);

    return ans;
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