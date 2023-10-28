#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;
    int arr[n]{};
    for(int i{}; i < n; ++i)
        cin >> arr[i];

    sort(arr, arr + n);

    int ans{max(arr[0] * arr[1], max(arr[0] * arr[1] * arr[n - 1], max(arr[n - 1] * arr[n - 2], arr[n - 1] * arr[n - 2] * arr[n - 3])))};
    cout << ans << '\n';

    return 0;
}