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

        int sum{};
        int arr[n]{};

        for(int i{}; i < n; ++i)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        int res{-1};
        int temp{};
        for(int i{1}; i < n - 1; ++i)
        {
            temp += arr[i - 1];

            if(temp == sum - temp - arr[i])
            {
                res = i + 1;
                break;
            }
        }

        cout << res << '\n';
    }

    return 0;
}