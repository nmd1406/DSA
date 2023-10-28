#include<bits/stdc++.h>

using namespace std;

int luyThua(int n, long long k)
{
    long long x = pow(2, n - 1);
    if(k == x)
        return n;
    if(k < x)
        return luyThua(n - 1, k);

    return luyThua(n - 1, k - x);
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        long long k{};
        cin >> n >> k;

        cout << static_cast<char>(luyThua(n, k) + 'A' - 1) << '\n';
    }

    return 0;
}