#include<iostream>

using namespace std;

int prime[1000001]{};

void sieve()
{
    for(int i{}; i <= 1000000; ++i)
        prime[i] = 1;

    prime[0] = prime[1] = 0;

    for(int i{2}; i <= 1000; ++i)
    {
        if(prime[i])
        {
            for(int j{i * i}; j <= 1000000; j += i)
                prime[j] = 0;
        }
    }
}

int main()
{
    int test{};
    cin >> test;

    sieve();

    while(test--)
    {
        int n{};
        cin >> n;

        int p{-1};

        for(int i{2}; i <= n; ++i)
        {
            if(prime[i] && prime[n - i])
            {
                p = i;
                break;
            }
        }

        if(p != -1)
            cout << p << ' ' << n - p << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}