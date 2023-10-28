#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n, k;
        cin >> n >> k;

        int mod = 1e9 + 7;

        if(!k)
            cout << 1 << '\n';
        else if(k > n)
            cout << 0 << '\n';
        else
        {
            long long res{1};
            for(int i{n - k + 1}; i <= n; ++i)
                res = (res * i) % mod;

            cout << res << '\n';
        }
    }

    return 0;
}