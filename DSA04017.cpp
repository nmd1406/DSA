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
        long long a[n]{};
        long long b[n - 1]{};

        for(int i{}; i < n; ++i)
            cin >> a[i];

        for(int i{}; i < n - 1; ++i)
            cin >> b[i];

        for(int i{}; i < n - 1; ++i)
        {
            if(a[i] != b[i])
            {
                cout << i + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}