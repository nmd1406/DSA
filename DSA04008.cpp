#include<iostream>
#include<unordered_map>

using namespace std;

const int mod = 1e9 + 7;
unordered_map<long long, long long> m{};

long long fibonacci(long long n)
{
    if(m.count(n))
        return m[n];
    
    long long k{n / 2};
    if(n % 2 == 0)
        return m[n] = (fibonacci(k) * fibonacci(k) + fibonacci(k - 1) * fibonacci(k - 1)) % mod;
    
    return m[n] = (fibonacci(k) * fibonacci(k + 1) + fibonacci(k - 1) * fibonacci(k)) % mod;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        long long n{};
        cin >> n;

        m[0] = 1;
        m[1] = 1;

        cout << fibonacci(n - 1) << '\n';
    }

    return 0;
}