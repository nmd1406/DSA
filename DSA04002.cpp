#include<iostream>

using namespace std;

const int mod = 1e9 + 7;

long long pow(long long n, long long r)
{
    if(r == 0)
        return 1;
    long long x{pow(n, r / 2)};
    if(r % 2 == 0)
        return x * x % mod;
    
    return n * (x * x % mod) % mod;
}

long long rev(long long n)
{
    long long num{};
    while(n)
    {
        num = num * 10 + n % 10;
        n /= 10;
    }

    return num;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        long long n{};
        cin >> n;

        long long reverse{rev(n)};
        cout << pow(n, reverse) << '\n';
    }

    return 0;
}