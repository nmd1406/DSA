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

        long long sum{};
        const int mod = 1e9 + 7;
        for(int i{}; i < n; ++i)
        {
            arr[i] *= i;
            sum = (sum + arr[i]) % mod;
        }

        cout << sum << '\n';
    }

    return 0;
}