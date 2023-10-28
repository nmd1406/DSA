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

        sort(arr, arr + n);
        int res{INT_MAX};
        for(int i{1}; i < n - 1; ++i)
            res = min(res, arr[i] - arr[i - 1]);
        
        cout << res << '\n';
    }

    return 0;
}