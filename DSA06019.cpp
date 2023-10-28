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
        unordered_map<int, int> m{};
        for(int i{}; i < n; ++i)
        {
            cin >> arr[i];
            ++m[arr[i]];
        }

        sort(arr, arr + n, [&](int a, int b)
                            {
                                if(m[a] == m[b])
                                    return a < b;
                                return m[a] > m[b];
                            });

        for(int i{}; i < n; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
    }

    return 0;
}