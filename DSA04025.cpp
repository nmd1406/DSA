#include<bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> fibo{};
const int mod = 1e9 + 7;

long long fibonacci(int n)
{
    if(fibo.count(n))
        return fibo[n];

    int k{n / 2};
    if(n % 2 == 0)
        return fibo[n] = (fibonacci(k) * fibonacci(k) + fibonacci(k - 1) * fibonacci(k - 1)) % mod;

    return fibo[n] = (fibonacci(k) * fibonacci(k + 1) + fibonacci(k) * fibonacci(k - 1)) % mod;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        fibo[0] = 1;
        fibo[1] = 1; 

        cout << fibonacci(n - 1) << '\n';
    }

    return 0;
}