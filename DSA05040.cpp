#include<bits/stdc++.h>

using namespace std;

int solve(int arr[], int n)
{
    int inc[n]{};
    int dec[n]{};
    int ans{};

    inc[0] = 1;
    dec[n - 1] = 1;

    for(int i{1}; i < n; ++i)
    {
        if(arr[i] > arr[i - 1])
            inc[i] = inc[i - 1] + 1;
        else
            inc[i] = 1;
    }

    for(int i{n - 2}; i >= 0; --i)
    {
        if(arr[i] > arr[i + 1])
            dec[i] = dec[i + 1] + 1;
        else
            dec[i] = 1;
    }

    ans = inc[0] + dec[0] - 1;

    for(int i{1}; i < n; ++i)
        ans = max(ans, inc[i] + dec[i] - 1);

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