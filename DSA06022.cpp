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
        if(arr[1] == arr[0])
            cout << -1 << '\n';
        else
            cout << arr[0] << ' ' << arr[1] << '\n';
    }

    return 0;
}