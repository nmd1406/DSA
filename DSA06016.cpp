#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int m{};
        cin >> n >> m;

        int a[n]{};
        int b[m]{};
        for(int i{}; i < n; ++i)
            cin >> a[i];
        for(int i{}; i < m; ++i)
            cin >> b[i];

        sort(a, a + n);
        sort(b, b + m);

        cout << 1ll * a[n - 1] * b[0] << '\n';
    }

    return 0;
}