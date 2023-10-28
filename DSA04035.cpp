#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long luyThua(long long a, long long b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    long long p = luyThua(a, b / 2);
    if(b % 2 == 0)
        return (p * p) % mod;
    
    return a * (p * p % mod) % mod;
}

int main()
{
    long long a{};
    long long b{};
    cin >> a >> b;

    while(a || b)
    {
        cout << luyThua(a, b) << '\n';
        cin >> a >> b;
    }

    return 0;
}