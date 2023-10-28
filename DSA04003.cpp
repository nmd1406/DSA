#include<iostream>

using namespace std;

const int mod = 123456789;

long long pow(long long n)
{
    if(n == 0)
        return 1 % mod;
    if(n == 1)
        return 2 % mod;

    long long x = pow(n / 2);
    if(n % 2 == 0)
        return x * x % mod;

    return 2 * (x * x) % mod;
}

int main()
{
    int test{};
    cin >> test;

    while (test--)
    {
        long long n{};
        cin >> n;

        cout << pow(n - 1) << '\n'; 
    }
    

    return 0;
}