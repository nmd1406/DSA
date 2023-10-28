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

        long long num1{};
        long long num2{};
        sort(arr, arr + n);
        for(int i{}; i < n; ++i)
        {
            if(i % 2 == 0)
                num1 = num1 * 10 + arr[i];
            else
                num2 = num2 * 10 + arr[i];
        }

        cout << num1 + num2 << '\n';
    }

    return 0;
}