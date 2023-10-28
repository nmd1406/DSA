#include<iostream>

using namespace std;

const int mod = 1e9 + 7;

long long pow(int n, int k)
{
    if(!k)
        return 1;

    long long x{pow(n, k / 2)};
    if(k % 2 == 0)
        return x * x % mod;
    
    return n * (x * x % mod) % mod;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int k{};
        cin >> n >> k;

        cout << pow(n, k) << '\n';
    }

    return 0;
}