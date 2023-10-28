#include<bits/stdc++.h>

using namespace std;

long long calc(int n)
{
    int mod = 1e9 + 7;

    long long catalan[n + 1]{};
    catalan[0] = catalan[1] = 1;

    for(int i{2}; i <= n; ++i)
    {
        for(int j{}; j < i; ++j)
            catalan[i] += (catalan[j] % mod * catalan[i - j - 1] % mod) % mod;
    }

    return catalan[n];
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n;
        cin >> n;

        cout << calc(n) << '\n';
    }

    return 0;
}