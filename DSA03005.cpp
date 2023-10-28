#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int k{};
        cin >> n >> k;
        int arr[n]{};

        for(int i{}; i < n; ++i)
            cin >> arr[i];

        sort(arr, arr + n);

        k = min(k, n - k);
        int sum1{};
        int sum2{};
        for(int i{}; i < n; ++i)
        {
            if(i < k)
                sum1 += arr[i];
            else
                sum2 += arr[i];
        }

        cout << sum2 - sum1 << '\n';
    }

    return 0;
}